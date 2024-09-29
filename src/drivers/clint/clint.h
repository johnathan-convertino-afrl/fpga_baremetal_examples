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

#include <stdint.h>

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
  volatile uint32_t reserved1[4095];
  /**
  * @var s_clint::mtimecmplw
  * timer lsw
  */
  volatile uint32_t mtimecmplw;
  /**
  * @var s_clint::mtimecmphw
  * timer msw
  */
  volatile uint32_t mtimecmphw;
  /**
  * @var s_clint::reserved2
  * unused regs
  */
  volatile uint32_t reserved2[8188];
  /**
  * @var s_clint::mtime_lw
  * time lsw
  */
  volatile uint32_t mtimelw;
  /**
  * @var s_clint::mtime_hw
  * time msw
  */
  volatile uint32_t mtimehw;
};

/*********************************************//**
  * @brief Initializes clint structure and device
  * to defaults.
  *
  * @param memory_address is the starting memory_address
  * of the gpio on the system bus.
  *
  * @return s_clint is a struct with a pointer to the
  * device memory address
  *************************************************/
struct s_clint *initClint(uint32_t memory_address);

/*********************************************//**
  * @brief set clint mtime compare
  *
  * @param p_clint is a struct pointing to the clint memory space
  * @param mtimecmp a value to set the mtime compare
  *************************************************/
void setClintMTimeCmp(struct s_clint *p_clint, uint64_t mtimecmp);

/*********************************************//**
  * @brief set clint mtime compare with an offset
  * that is based on mtime.
  *
  * @param p_clint is a struct pointing to the clint memory space
  * @param clock_offset number of ticks for the offset needed
  *************************************************/
void setClintMTimeCmpOffset(struct s_clint *p_clint, uint64_t clock_offset);

/*********************************************//**
  * @brief get clint mtime
  *
  * @param p_clint is a struct pointing to the clint memory space
  *
  * @return s_clint is a struct with a pointer to the
  * device memory address
  *************************************************/
uint64_t getClintMTime(struct s_clint *p_clint);

/*********************************************//**
  * @brief calculate number of seconds to for mtimercmp
  *
  * @param timer_freq_hz CLINT frequency in hz
  * @param seconds number of seconds desired
  *
  * @return Number of ticks that represents time requested
  *************************************************/
inline uint64_t calcMtimecmpSeconds(uint64_t timer_freq_hz, uint64_t seconds)
{
  return seconds * timer_freq_hz;
}

/*********************************************//**
  * @brief calculate number of milliseconds to for mtimercmp
  *
  * @param timer_freq_hz CLINT frequency in hz
  * @param milliseconds number of milliseconds desired
  *
  * @return Number of ticks that represents time requested
  *************************************************/
inline uint64_t calcMtimecmpMilliseconds(uint64_t timer_freq_hz, uint64_t milliseconds)
{
  return (milliseconds * timer_freq_hz)/1000;
}

/*********************************************//**
  * @brief calculate number of microseconds to for mtimercmp
  *
  * @param timer_freq_hz CLINT frequency in hz
  * @param microseconds number of microseconds desired
  *
  * @return Number of ticks that represents time requested
  *************************************************/
inline uint64_t calcMtimecmpMicroseconds(uint64_t timer_freq_hz, uint64_t microseconds)
{
  return (microseconds * timer_freq_hz)/1000000;
}

#ifdef __cplusplus
}
#endif

#endif
