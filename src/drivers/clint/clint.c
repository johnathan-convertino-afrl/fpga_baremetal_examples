/***************************************************************************//**
  * @file     clint.h
  * @brief    RISCV CLINT driver
  * @details  Baremetal C driver RISCV CLINT.
  * @author   Johnathan Convertino (johnathan.convertino.1@us.af.mil)
  * @date     08/26/2024
  * @version
  * - 0.0.0
  *
  * @license mit
  *
  * Copyright 2024 Johnathan Convertino
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is
  * furnished to do so, subject to the following conditions:
  *
  * The above copyright notice and this permission notice shall be included in
  * all copies or substantial portions of the Software.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  * IN THE SOFTWARE.
  *****************************************************************************/

#include <stdlib.h>

#include "clint.h"

// Initializes clint structure and device to defaults
struct s_clint *initClint(uint32_t memory_address)
{
  struct s_clint *p_temp = (struct s_clint *)memory_address;

  return p_temp;
}

// set clint mtime compare
void setClintMTimeCmp(struct s_clint *p_clint, uint64_t mtimecmp)
{
  p_clint->mtimecmphw = 0xFFFFFFFF;

  p_clint->mtimecmplw = (uint32_t)(mtimecmp & 0x00000000FFFFFFFFUL);
  p_clint->mtimecmphw = (uint32_t)(mtimecmp >> 32);
}

// set clint mtime compare with an offset
void setClintMTimeCmpOffset(struct s_clint *p_clint, uint64_t clock_offset)
{
  uint64_t mtime = getClintMTime(p_clint) + clock_offset;

  setClintMTimeCmp(p_clint, mtime);
}

// get clint mtime
uint64_t getClintMTime(struct s_clint *p_clint)
{
  uint32_t mtimeh_val;
  uint32_t mtimel_val;

  do {
      // There is a small risk the mtimeh will tick over after reading mtimel
      mtimeh_val = p_clint->mtimehw;
      mtimel_val = p_clint->mtimelw;
      // Poll mtimeh to ensure it's consistent after reading mtimel
      // The frequency of mtimeh ticking over is low
  } while (mtimeh_val != p_clint->mtimehw);

  return (uint64_t) ((((uint64_t)mtimeh_val)<<32) | mtimel_val);
}
