/***************************************************************************//**
  * @file     timer.h
  * @brief    Xilinx AXI TIMER driver
  * @details  Baremetal C driver targeting Xilinx based TIMER cores.
  *           Written with riscv or arm irq structure in mind.
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

#ifndef __TIMER_DRV_H
#define __TIMER_DRV_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct s_timer
 * @brief A struct to use for various timer devices. Will get memory mapped by init.
 */
struct s_timer
{
  /**
  * @union u_tcsr0
  * @brief Register tcsr0 with packed struct to access individual bits
  */
  union u_tcsr0
  {
    /**
    * @var s_timer:u_tcsr0:reg
    * full register
    */
    volatile uint32_t reg;

    /**
    * @union s_tcsr0_bits
    * @brief packed struct with bits.
    */
    struct s_tcsr0_bits
    {
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:md
      * Timer mode, 0 generate, 1 capture
      */
      volatile uint8_t md:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:ud
      * Timer up(0) or down(1)
      */
      volatile uint8_t ud:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:gen
      * Enable external generate signal
      */
      volatile uint8_t gen:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:cap
      * Enable external capture trigger
      */
      volatile uint8_t cap:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:arh
      * Auto reload (1) or Hold (0)
      */
      volatile uint8_t arh:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:load
      * Load (1) or No load (0) from TLR
      */
      volatile uint8_t load:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:eni
      * Enable interrupt
      */
      volatile uint8_t eni:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:en
      * Enable timer
      */
      volatile uint8_t en:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:intr
      * Indicates a interrupt has occured, clear on write 1
      */
      volatile uint8_t intr:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:pwm
      * Enable pulse width modulation
      */
      volatile uint8_t pwm:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:enaall
      * Enable all timers
      */
      volatile uint8_t enaall:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:casc
      * Enable cascade mode
      */
      volatile uint8_t casc:1;
      /**
      * @var s_timer:u_tcsr0:s_tcsr0_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:21;
    } bits;
  } tcsr0;
  /**
  * @var s_timer::tlr0
  * timer 0 load register
  */
  volatile uint32_t tlr0;
  /**
  * @var s_timer::tcr0
  * timer 0 counter register
  */
  volatile uint32_t tcr0;
  /**
  * @var s_timer::reserved
  * reserved
  */
  volatile uint32_t reserved[2];
  /**
  * @union u_tcsr1
  * @brief Register tcsr1 with packed struct to access individual bits
  */
   union u_tcsr1
  {
    /**
    * @var s_timer:u_tcsr1:reg
    * full register
    */
    volatile uint32_t reg;

    /**
    * @union s_tcsr1_bits
    * @brief packed struct with bits.
    */
    struct s_tcsr1_bits
    {
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:md
      * Timer mode, 0 generate, 1 capture
      */
      volatile uint8_t md:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:ud
      * Timer up(0) or down(1)
      */
      volatile uint8_t ud:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:gen
      * Enable external generate signal
      */
      volatile uint8_t gen:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:cap
      * Enable external capture trigger
      */
      volatile uint8_t cap:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:arh
      * Auto reload (1) or Hold (0)
      */
      volatile uint8_t arh:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:load
      * Load (1) or No load (0) from TLR
      */
      volatile uint8_t load:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:eni
      * Enable interrupt
      */
      volatile uint8_t eni:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:en
      * Enable timer
      */
      volatile uint8_t en:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:intr
      * Indicates a interrupt has occured, clear on write 1
      */
      volatile uint8_t intr:1;
      /**
      * @var s_timer:u_tcsr1:s_tcs1_bits:pwm
      * Enable pulse width modulation
      */
      volatile uint8_t pwm:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:enaall
      * Enable all timers
      */
      volatile uint8_t enaall:1;
      /**
      * @var s_timer:u_tcsr1:s_tcsr1_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:22;
    } bits;
  } tcsr1;
  /**
  * @var s_timer::tlr1
  * timer 1 load register
  */
  volatile uint32_t tlr1;
  /**
  * @var s_timer::tcr1
  * timer 1 counter register
  */
  volatile uint32_t tcr1;
};

/*********************************************//**
  * @brief Initializes timer structure and device
  * to defaults, no IRQ, 0 counter.
  *
  * @param memory_address is the starting memory_address
  * of the timer on the system bus.
  *
  * @return s_timer is a struct with a pointer to the
  * device memory address
  *************************************************/
struct s_timer *initTimer(uint32_t memory_address);

#ifdef __cplusplus
}
#endif

#endif
