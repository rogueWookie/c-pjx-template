#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>


typedef enum
{
    BUFFERS_SUCCESS = 1,
    BUFFERS_FAILURE = 0
} buffers_errors_t;

typedef struct
{
    uint8_t** buffers;
    uint32_t number_of_buffers;
    uint32_t size_of_buffers;
} buffers_instance_t;

uint32_t buffers_init ( 
        buffers_instance_t** inst, 
        uint32_t size_of_buffers, 
        uint32_t number_of_buffers)
{
    // create instance
    *inst = (buffers_instance_t*)malloc(sizeof(buffers_instance_t));
    if ( !(*inst) )
    {       
        printf("[%s %d] %s\n", __FUNCTION__, __LINE__, 
                "error initializing instance");
        return BUFFERS_FAILURE;
    }

    // create array of pointers for all buffers
    (*inst)->buffers = (uint8_t**)calloc(number_of_buffers, sizeof(uint8_t*));
    for ( uint8_t i = 0; i < number_of_buffers; i++ )
    {
        // now create the buffers to initialize the array of pointers
        (*inst)->buffers[i] = (uint8_t*)calloc(
                size_of_buffers, sizeof(uint8_t));
        if ( !(*inst)->buffers[i] )
        {
            printf("[%s %d] %s\n", __FUNCTION__, __LINE__, 
                    "error initializing buffers");
            return BUFFERS_FAILURE;
        }
    }

    (*inst)->size_of_buffers = size_of_buffers;
    (*inst)->number_of_buffers = number_of_buffers;
    
    return BUFFERS_SUCCESS;
}

int main ()
{
    buffers_instance_t* instance;
    
    uint32_t number_of_buffers = 2;
    uint32_t size_of_buffers = 2;

    //  test good init
    assert( buffers_init( &instance, number_of_buffers, size_of_buffers ) 
            == BUFFERS_SUCCESS );

    assert( number_of_buffers == instance->number_of_buffers );
    assert( size_of_buffers == instance->size_of_buffers );

    for ( uint8_t i = 0; i < instance->number_of_buffers; i++ )
    {
        //  test good pointers
        assert( NULL != instance->buffers[i] );
        
        //  test good initial values
        assert( 0 == *(instance->buffers[i]) );
    }
}







