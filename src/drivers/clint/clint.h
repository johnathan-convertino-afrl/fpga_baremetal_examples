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

#ifndef __CLINT_DRV_H
#define __CLINT_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct s_clint
 * @brief A struct to use for various clint devices. Will get memory mapped by init.
 */
struct s_clint
{
  /**
  * @var s_clint::msip
  * MSIP for hart 0
  */
  volatile uint32_t msip;
  /**
  * @var s_clint::reserved1
  * unused regs
  */
  volatile uint32_t reserved1[16380];
  /**
  * @var s_clint::mtimecmp0
  * timer lsw
  */
  volatile uint32_t mtimecmp0;
  /**
  * @var s_clint::mtimecmp1
  * timer msw
  */
  volatile uint32_t mtimecmp1;
  /**
  * @var s_clint::reserved2
  * unused regs
  */
  volatile uint32_t reserved2[32752];
  /**
  * @var s_clint::mtime0
  * time lsw
  */
  volatile uint32_t mtime0;
  /**
  * @var s_clint::mtime1
  * time msw
  */
  volatile uint32_t mtime1;
  /**
  * @var s_clint::reserved3
  * unused regs
  */
  volatile uint32_t reserved3[9];
};

/*********************************************//**
  * @brief Initializes gpio structure and device
  * to defaults, no IRQ, 0 output data, ALL outputs.
  *
  * @param memory_address is the starting memory_address
  * of the gpio on the system bus.
  *
  * @return s_clint is a struct with a pointer to the
  * device memory address
  *************************************************/
inline struct s_clint *initGpio(uint32_t memory_address);

#endif

#ifdef __cplusplus
}
#endif


