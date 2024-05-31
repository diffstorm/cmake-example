#ifndef CRC16_H
#define CRC16_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

uint16_t crc16_ccitt(const uint8_t *data, size_t length);

#ifdef __cplusplus
}
#endif

#endif // CRC16_H
