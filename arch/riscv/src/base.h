/*
   Register access functions for RISC-V system registers.
   SPDX-License-Identifier: Unlicense

   https://five-embeddev.com/

*/

#ifndef RISCV_BASE_H
#define RISCV_BASE_H

#include <stdint.h>

static inline void delay(uint32_t len) {

  uint32_t index = 0;

  for(index = 0; index < len; index++)
  {
    __asm__ volatile ("nop");
  }
}

#endif // #define RISCV_BASE_H
