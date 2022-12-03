#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <zlib.h>

// gcc file.c -lz

uint32_t crc_crc(uint8_t *bytes, uint8_t bytessize)
{
    uint32_t crc = crc32(0L, Z_NULL, 0);

    for (uint32_t i = 0; i < bytessize; ++i)
    {
        crc = crc32(crc, bytes + i, 1);
    }

    /* printf("CRC32 value is: 0x%08x\n", crc); */
    return crc;
}

uint32_t crc_chk(uint8_t* bytes, uint8_t bytessize)
{
    uint32_t sum = 0;
    for (uint32_t i = 0; i < bytessize; ++i)
    {
        sum = *(bytes + i) + sum;
    }

    /* printf("CHECKSUM value is: 0x%04x\n", sum); */
    return sum;
}
