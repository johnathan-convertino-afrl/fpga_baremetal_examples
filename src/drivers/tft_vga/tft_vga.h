/***************************************************************************//**
  * @file     tft_vga.h
  * @brief    Xilinx AXI TFT_VGA driver
  * @details  Baremetal C driver targeting Xilinx based TFT_VGA lite cores.
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

#ifndef __TFT_VGA_DRV_H
#define __TFT_VGA_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct s_tft_vga
 * @brief A struct to use for various tft_vga devices. Will get memory mapped by init.
 */
struct s_tft_vga
{
  /**
  * @var s_tft_vga::base_addr
  * Base address register aligned to 2MB boundry
  */
  volatile uint32_t base_addr;

  /**
  * @union u_control
  * @brief Register control with packed struct to access individual bits
  */
  union u_control
  {
    /**
    * @var s_tft_vga:u_control:reg
    * Status register
    */
    volatile uint32_t reg;

    /**
    * @union s_control_bits
    * @brief packed struct with bits.
    */
    struct s_control_bits
    {
      /**
      * @var s_tft_vga:u_control:s_control_bits:tde
      * TFT display enable bit
      */
      volatile uint8_t tde:1;
      /**
      * @var s_tft_vga:u_control:s_control_bits:dps
      * Display Scan control bit
      */
      volatile uint8_t dps:1;
      /**
      * @var s_tft_vga:u_control:s_control_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:30;
    } bits;
  } control;

  /**
  * @union u_iesr
  * @brief Register interupt enable and status with packed struct to access individual bits
  */
  union u_iesr
  {
    /**
    * @var s_tft_vga:u_iesr:reg
    * iesr register
    */
    volatile uint32_t reg;

    /**
    * @union s_iesr_bits
    * @brief packed struct with bits.
    */
    struct s_iesr_bits
    {
      /**
      * @var s_tft_vga:u_iesr:s_iesr_bits:status
      * Status of vsync pulse
      */
      volatile uint8_t status:1;
      /**
      * @var s_tft_vga:u_iesr:s_iesr_bits:unused
      * Unused bits
      */
      volatile uint8_t unused:2;
      /**
      * @var s_tft_vga:u_iesr:s_iesr_bits:intr_ena
      * Enable vsync interrupt
      */
      volatile uint8_t intr_ena:1;
      /**
      * @var s_tft_vga:u_iesr:s_iesr_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:28;
    } bits;
  } iesr;

  /**
  * @union u_ccr
  * @brief Register chrontel configuration with packed struct to access individual bits
  */
  union u_ccr
  {
    /**
    * @var s_tft_vga:u_ccr:reg
    * ccr register
    */
    volatile uint32_t reg;

    /**
    * @union s_ccr_bits
    * @brief packed struct with bits.
    */
    struct s_ccr_bits
    {
      /**
      * @var s_tft_vga:u_ccr:s_ccr_bits:data
      * Write data to chip
      */
      volatile uint8_t data;
      /**
      * @var s_tft_vga:u_ccr:s_ccr_bits:addr
      * Set address of chip
      */
      volatile uint8_t addr;
      /**
      * @var s_tft_vga:u_ccr:s_ccr_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:29;
      /**
      * @var s_tft_vga:u_ccr:s_ccr_bits:start
      * Start data transmission to chip
      */
      volatile uint8_t start:1;
    } bits;
  } ccr;

  /**
  * @var s_tft_vga::ext_base_addr_low
  * Extended base address for address busses greater than 32 bit. (LOW)
  */
  volatile uint32_t ext_base_addr_low;

  /**
  * @var s_tft_vga::ext_base_addr_high
  * Extended base address for address busses greater than 32 bit. (HIGH)
  */
  volatile uint32_t ext_base_addr_high;
};

/*********************************************//**
  * @brief Initializes tft_vga structure and device
  * to defaults, no IRQ, default base_address.
  *
  * @param memory_address is the starting memory_address
  * of the tft_vga on the system bus.
  *
  * @return s_tft_vga is a struct with a pointer to the
  * device memory address
  *************************************************/
struct s_tft_vga *initTFTvga(uint32_t memory_address);

#ifdef __cplusplus
}
#endif

#endif

