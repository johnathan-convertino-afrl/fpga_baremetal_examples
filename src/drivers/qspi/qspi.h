/***************************************************************************//**
  * @file     qspi.h
  * @brief    Xilinx AXI QSPI driver
  * @details  Baremetal C driver targeting Xilinx based QSPI lite cores.
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

#ifndef __QSPI_DRV_H
#define __QSPI_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct s_qspi
 * @brief A struct to use for various qspi devices. Will get memory mapped by init.
 */
struct s_qspi
{
  /**
  * @var s_qspi::unused_array0
  * unused section of register map 0x00 - 0x1C
  */
  volatile uint32_t unused_array0[8];
  /**
  * @union u_gier
  * @brief Register gier with packed struct to access individual bits
  */
  union u_gier
  {
    /**
    * @var s_qspi:u_gier:reg
    * Global interupt register
    */
    volatile uint32_t reg;

    /**
    * @union s_gier_bits
    * @brief packed struct with bits.
    */
    struct s_gier_bits
    {
      /**
      * @var s_qspi:u_gier:s_gier_bits:reserver
      * Unused bits
      */
      volatile uint32_t reserved:31;
      /**
      * @var s_qspi:u_gier:s_gier_bits:gie
      * Global interupt enable bit
      */
      volatile uint8_t gie:1;
    } bits;
  } gier;

  /**
  * @union u_isr
  * @brief Register isr with packed struct to access individual bits
  */
  union u_isr
  {
    /**
    * @var s_qspi:u_isr:reg
    * Global interupt register
    */
    volatile uint32_t reg;

    /**
    * @union s_isr_bits
    * @brief packed struct with bits.
    */
    struct s_isr_bits
    {
      /**
      * @var s_qspi:u_isr:s_isr_bits:modf
      * Mode-fault error
      */
      volatile uint8_t modf:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:smodf
      * Slave mode-fault error
      */
      volatile uint8_t smodf:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:dtr_emp
      * Data transmit register is empty
      */
      volatile uint8_t dtr_emp:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:dtr_undr
      * Data transmit register is underrun
      */
      volatile uint8_t dtr_undr:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:drr_full
      * Data receive register is full
      */
      volatile uint8_t drr_full:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:drr_overr
      * Data receive register is overrun
      */
      volatile uint8_t drr_overr:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:tx_fifo_hemp
      * TX fifo half empty
      */
      volatile uint8_t tx_fifo_hemp:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:ssm
      * slave select mode
      */
      volatile uint8_t ssm:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:drr_nemp
      * data receive is not empty.
      */
      volatile uint8_t drr_nemp:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:cpol_err
      * Dual or quad mode.
      */
      volatile uint8_t cpol_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:sm_err
      * Slave mode error.
      */
      volatile uint8_t sm_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:msb_err
      * MSB error.
      */
      volatile uint8_t msb_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:loop_err
      * Loopback error.
      */
      volatile uint8_t loop_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:cmd_err
      * Command error.
      */
      volatile uint8_t cmd_err:1;

      /**
      * @var s_qspi:u_ier:s_isr_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:18;
    } bits;
  } isr;

  /**
  * @union u_ier
  * @brief Register ier with packed struct to access individual bits
  */
  union u_ier
  {
    /**
    * @var s_qspi:u_ier:reg
    * Global interupt register
    */
    volatile uint32_t reg;

    /**
    * @union s_ier_bits
    * @brief packed struct with bits.
    */
    struct s_ier_bits
    {
      /**
      * @var s_qspi:u_isr:s_isr_bits:modf
      * Mode-fault error
      */
      volatile uint8_t modf:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:smodf
      * Slave mode-fault error
      */
      volatile uint8_t smodf:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:dtr_emp
      * Data transmit register is empty
      */
      volatile uint8_t dtr_emp:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:dtr_undr
      * Data transmit register is underrun
      */
      volatile uint8_t dtr_undr:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:drr_full
      * Data receive register is full
      */
      volatile uint8_t drr_full:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:drr_overr
      * Data receive register is overrun
      */
      volatile uint8_t drr_overr:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:tx_fifo_hemp
      * TX fifo half empty
      */
      volatile uint8_t tx_fifo_hemp:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:ssm
      * slave select mode
      */
      volatile uint8_t ssm:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:drr_nemp
      * data receive is not empty.
      */
      volatile uint8_t drr_nemp:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:cpol_err
      * Dual or quad mode.
      */
      volatile uint8_t cpol_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:sm_err
      * Slave mode error.
      */
      volatile uint8_t sm_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:msb_err
      * MSB error.
      */
      volatile uint8_t msb_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:loop_err
      * Loopback error.
      */
      volatile uint8_t loop_err:1;

      /**
      * @var s_qspi:u_isr:s_isr_bits:cmd_err
      * Command error.
      */
      volatile uint8_t cmd_err:1;

      /**
      * @var s_qspi:u_ier:s_isr_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:18;
    } bits;
  } ier;

  /**
  * @var s_qspi::unused_array1
  * unused section of register map
  */
  volatile uint32_t unused_array1[7];

  /**
  * @var s_qspi::srr
  * software reset register
  */
  volatile uint32_t srr;

  /**
  * @var s_qspi::unused_array2
  * unused section of register map
  */
  volatile uint32_t unused_array2[9];

  /**
  * @union u_control
  * @brief Register control with packed struct to access individual bits
  */
  union u_control
  {
    /**
    * @var s_qspi:u_control:reg
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
      * @var s_qspi:u_control:s_control_bits:loop_mode
      * Loopback mode
      */
      volatile uint8_t loop_mode:1;
      
      /**
      * @var s_qspi:u_control:s_control_bits:spe
      * System enable
      */
      volatile uint8_t spe:1;
      
      /**
      * @var s_qspi:u_control:s_control_bits:ms_mode
      * Master or slave mode
      */
      volatile uint8_t ms_mode:1;

      /**
      * @var s_qspi:u_control:s_control_bits:cpol
      * Clock polarity
      */
      volatile uint8_t cpol:1;

      /**
      * @var s_qspi:u_control:s_control_bits:cpha
      * Clock phase
      */
      volatile uint8_t cpha:1;

      /**
      * @var s_qspi:u_control:s_control_bits:tx_fifo_rst
      * Transmit FIFO reset
      */
      volatile uint8_t tx_fifo_rst:1;

      /**
      * @var s_qspi:u_control:s_control_bits:rx_fifo_rst
      * Receive FIFO reset
      */
      volatile uint8_t rx_fifo_rst:1;

      /**
      * @var s_qspi:u_control:s_control_bits:ms_sel
      * Manual slave aselect assertion enable
      */
      volatile uint8_t ms_sel:1;

      /**
      * @var s_qspi:u_control:s_control_bits:mtrans_inh
      * Master transaction inhibit
      */
      volatile uint8_t mtrans_inh:1;

      /**
      * @var s_qspi:u_control:s_control_bits:lsb_fir
      * LSB first
      */
      volatile uint8_t lsb_fir:1;

      /**
      * @var s_qspi:u_control:s_control_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:22;
    } bits;
  } control;

  /**
  * @union u_status
  * @brief Register status with packed struct to access individual bits
  */
  union u_status
  {
    /**
    * @var s_qspi:u_status:reg
    * status register
    */
    volatile uint32_t reg;

    /**
    * @union s_status_bits
    * @brief packed struct with bits.
    */
    struct s_status_bits
    {
      /**
      * @var s_qspi:u_iesr:s_status_bits:rx_emp
      * Receive empty
      */
      volatile uint8_t rx_emp:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:rx_full
      * Receive full
      */
      volatile uint8_t rx_full:2;

      /**
      * @var s_qspi:u_iesr:s_status_bits:tx_empty
      * Transmit empty
      */
      volatile uint8_t tx_empty:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:tx_full
      * Transmit full
      */
      volatile uint8_t tx_full:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:modf
      * Mode-fault error flag
      */
      volatile uint8_t modf:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:sm_sel
      * Slave mode select
      */
      volatile uint8_t sm_sel:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:cpol_err
      * CPOL CPHA error
      */
      volatile uint8_t cpol_err:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:sm_err
      * Slave mode error
      */
      volatile uint8_t sm_err:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:msb_err
      * MSB error
      */
      volatile uint8_t msb_err:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:loop_err
      * Loopback error
      */
      volatile uint8_t loop_err:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:cmd_err
      * Command error
      */
      volatile uint8_t cmd_err:1;

      /**
      * @var s_qspi:u_iesr:s_status_bits:reserved
      * Unused bits
      */
      volatile uint32_t reserved:21;
    } bits;
  } status;

  /**
  * @var s_qspi::dtr
  * data transmit register
  */
  volatile uint32_t dtr;

  /**
  * @var s_qspi::drr
  * data receive register
  */
  volatile uint32_t drr;

  /**
  * @var s_qspi::ssr
  * slave select register
  */
  volatile uint32_t ssr;

  /**
  * @var s_qspi::dtr_fifo_itm
  * items contained in data transmit register fifo
  */
  volatile uint32_t dtr_fifo_itm;

  /**
  * @var s_qspi::drr_fifo_itm
  * items contained in data receive register fifo
  */
  volatile uint32_t drr_fifo_itm;

};

/*********************************************//**
  * @brief Initializes qspi structure and device
  * to defaults, no IRQ.
  *
  * @param memory_address is the starting memory_address
  * of the qspi on the system bus.
  *
  * @return s_qspi is a struct with a pointer to the
  * device memory address
  *************************************************/
 struct s_qspi *initQspi(uint32_t memory_address);

#endif

#ifdef __cplusplus
}
#endif


