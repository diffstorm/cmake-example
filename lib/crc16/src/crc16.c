#include "crc16.h"

uint16_t crc16_ccitt(const uint8_t *data, size_t length) {
    uint16_t crc = 0xFFFF;
    while (length--) {
        crc ^= *data++ << 8;
        for (int i = 0; i < 8; i++) {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc = crc << 1;
        }
    }
    return crc;
}
