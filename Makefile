EXE ?= main

BLD_DIR ?= ./bld
SRC_DIR ?= ./src

SRC := $(shell find $(SRC_DIR) -name *.cpp -or -name *.c -or -name *.s)
OBJ := $(SRC:%=$(BLD_DIR)/%.o)
DEP := $(OBJ:.o=.d)

INC_DIR := $(shell find $(SRC_DIR) -type d)
INC_FLG := $(addprefix -I,$(INC_DIR))

LKD_FLG ?= -lz -lpthread
CPP_FLG ?= $(INC_FLG) -MMD -MP -Werror -Wall -Wextra
$(BLD_DIR)/$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LKD_FLG)

# assembly
$(BLD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BLD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPP_FLG) $(CFLAGS) -c $< -o $@

# c++ source
$(BLD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPP_FLG) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BLD_DIR)

-include $(DEP)

MKDIR_P ?= mkdir -p

