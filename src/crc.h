#ifndef __CALC_H__
#define __CALC_H__

#include <stdint.h>

uint32_t crc_crc(uint8_t* bytes, uint8_t bytessize);
uint32_t crc_chk(uint8_t* bytes, uint8_t bytessize);

#endif /*__CALC_H__*/
