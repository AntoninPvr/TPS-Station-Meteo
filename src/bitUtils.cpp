#include "bitUtils.h"

uint8_t firstBit(uint8_t value) {
  uint8_t tmp = 0;
  uint8_t mask = 1;

  for(int8_t i = 0; i < 4; i++) {
    tmp = ((value & mask) << (7 - 2*i)) | tmp;
    mask = mask << 1;
  }
  return(tmp);
}

uint8_t lastBit(uint8_t value) {
  uint8_t tmp = 0;
  uint8_t mask = 0x10;

  for(int8_t i = 0; i < 4; i++) {
    tmp = ((value & mask) >> (1+2*i)) | tmp;
    mask = mask << 1;
  }
  tmp = tmp << 4;
  return(tmp);
}
