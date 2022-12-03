#include "CppUTest/TestHarness.h"

extern "C"
{
#include "crc.h"
}

TEST_GROUP(example)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(example, all)
{
    uint8_t buf[] = {1,2,3};
    CHECK_EQUAL(0x55bc801d, crc_crc(buf, sizeof(buf)));
    CHECK_EQUAL(0x6, crc_chk(buf, sizeof(buf)));
}

