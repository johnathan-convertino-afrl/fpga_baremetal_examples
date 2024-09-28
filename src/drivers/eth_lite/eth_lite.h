/***************************************************************************//**
  * @file     eth_lite.h
  * @brief    Xilinx AXI ETH_LITE driver
  * @details  Baremetal C driver targeting Xilinx based ETH_LITE cores.
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

#ifndef __ETH_LITE_DRV_H
#define __ETH_LITE_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @struct s_eth_lite
 * @brief A struct to use for various eth_lite devices. Will get memory mapped by init.
 */
struct s_eth_lite
{
  /**
  * @var s_eth_lite::tx_ping_buffer
  * TX Ping buffer 0x000 - 0x7DC
  */
  volatile uint32_t tx_ping_buffer[504];

  /**
  * @var s_eth_lite::unused_array0
  * Unused registers
  */
  volatile uint32_t unused_array0[8];

  /**
  * @union u_mdio_address
  * mdio address
  */
  union u_mdio_address
  {
    /**
    * @var s_eth_lite:u_mdio_address:reg
    * MDIO address register
    */
    volatile uint32_t reg;

    /**
    * @union s_mdio_addr_bits
    * @brief packed struct with bits.
    */
    struct s_mdio_addr_bits
    {
      /**
      * @var s_eth_lite:u_mdio_address:s_mdio_addr_bits:reg_addr
      * Phy register address
      */
      volatile uint32_t reg_addr:5;
      /**
      * @var s_eth_lite:u_mdio_address:s_mdio_addr_bits:phy_addr
      * Phy device address
      */
      volatile uint8_t phy_addr:5;
      /**
      * @var s_eth_lite:u_mdio_address:s_mdio_addr_bits:op
      * operation access type
      */
      volatile uint8_t op:1;
      /**
      * @var s_eth_lite:u_mdio_address:s_mdio_addr_bits:reserved
      * Phy device address
      */
      volatile uint8_t reserved:21;
    } bits;
  } mdio_addr;

  /**
  * @var s_eth_lite::mdio_write_data
  * MDIO data that needs to be written
  */
  volatile uint32_t mdio_write_data;

  /**
  * @var s_eth_lite::mdio_read_data
  * MDIO data that needs to be read
  */
  volatile uint32_t mdio_read_data;

  /**
  * @union u_mdio_cntrl
  * mdio address
  */
  union u_mdio_cntrl
  {
    /**
    * @var s_eth_lite:u_mdio_cntrl:reg
    * MDIO address register
    */
    volatile uint32_t reg;

    /**
    * @union u_mdio_cntrl_bits
    * @brief packed struct with bits.
    */
    struct u_mdio_cntrl_bits
    {
      /**
      * @var s_eth_lite:u_mdio_cntrl:u_mdio_cntrl_bits:status
      * MDIO status
      */
      volatile uint32_t status:1;
      /**
      * @var s_eth_lite:u_mdio_cntrl:u_mdio_cntrl_bits:unused
      * Unused bits
      */
      volatile uint8_t unused:2;
      /**
      * @var s_eth_lite:u_mdio_cntrl:u_mdio_cntrl_bits:enable
      * MDIO enable
      */
      volatile uint8_t enable:1;
      /**
      * @var s_eth_lite:u_mdio_cntrl:u_mdio_cntrl_bits:reserved
      * Reserved bits
      */
      volatile uint8_t reserved:28;
    } bits;
  } mdio_cntrl;

  /**
  * @union u_trans_ping_packet_len
  * transmit packet length
  */
  union u_trans_ping_packet_len
  {
    /**
    * @var s_eth_lite:u_trans_ping_packet_len:reg
    * MDIO address register
    */
    volatile uint32_t reg;

    /**
    * @union u_mdio_cntrl_bits
    * @brief packed struct with bits.
    */
    struct u_trans_packet_len_bits
    {
      /**
      * @var s_eth_lite:u_trans_ping_packet_len:u_trans_packet_len_bits:lsb
      * lower 8 bits of frame length
      */
      volatile uint32_t lsb:8;

      /**
      * @var s_eth_lite:u_trans_ping_packet_len:u_trans_packet_len_bits:msb
      * upper 8 bits of fram length
      */
      volatile uint8_t msb:8;

      /**
      * @var s_eth_lite:u_trans_ping_packet_len:u_trans_packet_len_bits:reserved
      * Reserved bits
      */
      volatile uint8_t reserved:16;
    } bits;
  } trans_ping_packet_len;

  /**
  * @union u_gier
  * @brief Register gier with packed struct to access individual bits
  */
  union u_gier
  {
    /**
    * @var s_gpio:u_gier:reg
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
      * @var s_gpio:u_gier:s_gier_bits:reserver
      * Unused bits
      */
      volatile uint32_t reserved:31;
      /**
      * @var s_gpio:u_gier:s_gier_bits:gie
      * Global interupt enable bit
      */
      volatile uint8_t gie:1;
    } bits;
  } gier;

  /**
  * @union u_trans_ping_cntrl
  * @brief Register trasmit control with packed struct to access individual bits
  */
  union u_trans_ping_cntrl
  {
    /**
    * @var s_eth_lite:u_trans_ping_cntrl:reg
    * control reg full access
    */
    volatile uint32_t reg;

    /**
    * @union s_trans_cntrl_bits
    * @brief packed struct with bits.
    */
    struct s_trans_cntrl_bits
    {
      /**
      * @var s_eth_lite:u_trans_ping_cntrl:s_trans_cntrl_bits:status
      * Status of transmit ping buffer
      */
      volatile uint32_t status:1;

      /**
      * @var s_eth_lite:u_trans_ping_cntrl:s_trans_cntrl_bits:program
      * Program mac address?
      */
      volatile uint8_t program:1;

      /**
      * @var s_eth_lite:u_trans_ping_cntrl:s_trans_cntrl_bits:unused
      * unused bits
      */
      volatile uint8_t unused:1;

      /**
      * @var s_eth_lite:u_trans_ping_cntrl:s_trans_cntrl_bits:intr_ena
      * unused bits
      */
      volatile uint8_t intr_ena:1;

      /**
      * @var s_eth_lite:u_trans_ping_cntrl:s_trans_cntrl_bits:loopback
      * internal loopback mode
      */
      volatile uint8_t loopback:1;

      /**
      * @var s_eth_lite:u_trans_ping_cntrl:s_trans_cntrl_bits:reserved
      * Reserved bits
      */
      volatile uint8_t reserved:27;
    } bits;
  } trans_ping_cntrl;

  /**
  * @var s_eth_lite::tx_pong_buffer
  * TX Ping buffer 0x800 - 0xFE0
  */
  volatile uint32_t tx_pong_buffer[504];

  /**
  * @var s_eth_lite::unused_array1
  * Unused registers
  */
  volatile uint32_t unused_array1[2];

  /**
  * @union u_trans_pong_packet_len
  * transmit packet length
  */
  union u_trans_pong_packet_len
  {
    /**
    * @var s_eth_lite:u_trans_pong_packet_len:reg
    * MDIO address register
    */
    volatile uint32_t reg;

    /**
    * @union u_mdio_cntrl_bits
    * @brief packed struct with bits.
    */
    struct u_trans_packet_len_bits
    {
      /**
      * @var s_eth_lite:u_trans_pong_packet_len:u_trans_packet_len_bits:lsb
      * lower 8 bits of frame length
      */
      volatile uint32_t lsb:8;

      /**
      * @var s_eth_lite:u_trans_pong_packet_len:u_trans_packet_len_bits:msb
      * upper 8 bits of fram length
      */
      volatile uint8_t msb:8;

      /**
      * @var s_eth_lite:u_trans_pong_packet_len:u_trans_packet_len_bits:reserved
      * Reserved bits
      */
      volatile uint8_t reserved:16;
    } bits;
  } trans_pong_packet_len;

  /**
  * @var s_eth_lite::unused_array2
  * Unused registers
  */
  volatile uint32_t unused_array2[1];

  /**
  * @union u_trans_pong_cntrl
  * @brief Register trasmit control with packed struct to access individual bits
  */
  union u_trans_pong_cntrl
  {
    /**
    * @var s_eth_lite:u_trans_pong_cntrl:reg
    * control reg full access
    */
    volatile uint32_t reg;

    /**
    * @union s_trans_cntrl_bits
    * @brief packed struct with bits.
    */
    struct s_trans_cntrl_bits
    {
      /**
      * @var s_eth_lite:u_trans_pong_cntrl:s_trans_cntrl_bits:status
      * Status of transmit ping buffer
      */
      volatile uint32_t status:1;

      /**
      * @var s_eth_lite:u_trans_pong_cntrl:s_trans_cntrl_bits:program
      * Program mac address?
      */
      volatile uint8_t program:1;

      /**
      * @var s_eth_lite:u_trans_pong_cntrl:s_trans_cntrl_bits:reserved
      * reserved bits
      */
      volatile uint8_t reserved:30;
    } bits;
  } trans_pong_cntrl;

  /**
  * @var s_eth_lite::rx_ping_buffer
  * TX Ping buffer 0x1000 - 0x17DC
  */
  volatile uint32_t rx_ping_buffer[504];

  /**
  * @var s_eth_lite::unused_array3
  * Unused registers
  */
  volatile uint32_t unused_array3[19];

  /**
  * @union u_recv_ping_cntrl
  * @brief Register receive control with packed struct to access individual bits
  */
  union u_recv_ping_cntrl
  {
    /**
    * @var s_eth_lite:u_recv_ping_cntrl:reg
    * control reg full access
    */
    volatile uint32_t reg;

    /**
    * @union s_recv_cntrl_bits
    * @brief packed struct with bits.
    */
    struct s_recv_cntrl_bits
    {
      /**
      * @var s_eth_lite:u_recv_ping_cntrl:s_recv_cntrl_bits:status
      * Status of transmit ping buffer
      */
      volatile uint32_t status:1;

      /**
      * @var s_eth_lite:u_recv_ping_cntrl:s_recv_cntrl_bits:unused
      * unused bits
      */
      volatile uint8_t unused:2;

      /**
      * @var s_eth_lite:u_recv_ping_cntrl:s_recv_cntrl_bits:intr_ena
      * unused bits
      */
      volatile uint8_t intr_ena:1;

      /**
      * @var s_eth_lite:u_recv_ping_cntrl:s_recv_cntrl_bits:reserved
      * Reserved bits
      */
      volatile uint8_t reserved:28;
    } bits;
  } recv_ping_cntrl;

  /**
  * @var s_eth_lite::rx_pong_buffer
  * TX Ping buffer 0x1800 - 0x1FDC
  */
  volatile uint32_t rx_pong_buffer[504];

  /**
  * @var s_eth_lite::unused_array3
  * Unused registers
  */
  volatile uint32_t unused_array3[19];

  /**
  * @union u_recv_pong_cntrl
  * @brief Register receive control with packed struct to access individual bits
  */
  union u_recv_pong_cntrl
  {
    /**
    * @var s_eth_lite:u_recv_pong_cntrl:reg
    * control reg full access
    */
    volatile uint32_t reg;

    /**
    * @union s_recv_cntrl_bits
    * @brief packed struct with bits.
    */
    struct s_recv_cntrl_bits
    {
      /**
      * @var s_eth_lite:u_recv_pong_cntrl:s_recv_cntrl_bits:status
      * Status of transmit ping buffer
      */
      volatile uint32_t status:1;

      /**
      * @var s_eth_lite:u_recv_pong_cntrl:s_trans_cntrl_bits:reserved
      * Reserved bits
      */
      volatile uint8_t reserved:31;
    } bits;
  } recv_pong_cntrl;
};

/*********************************************//**
  * @brief Initializes eth_lite structure and device
  * to defaults, no IRQ.
  *
  * @param memory_address is the starting memory_address
  * of the eth_lite on the system bus.
  *
  * @return s_eth_lite is a struct with a pointer to the
  * device memory address
  *************************************************/
struct s_eth_lite *initEthLite(uint32_t memory_address);

/*********************************************//**
  * @brief Read eth_lite receive data
  *
  * @param p_eth_lite pre-initialized struct from initEthLite
  * @param p_data Pointer to a buffer for data (min 504 words (32bit))
  *
  * @return Length of packet
  *************************************************/
uint32_t readEthLiteRXbuffer(struct s_eth_lite *p_eth_lite, uint32_t *p_data);

/*********************************************//**
  * @brief Write eth_lite transmit data
  *
  * @param p_eth_lite pre-initialized struct from initEthLite
  * @param p_data Pointer to a buffer to read data from.
  * @param len Length of the data buffer in words (32 bit)
  *************************************************/
void writeEthLiteTXbuffer(struct s_eth_lite *p_eth_lite, uint32_t *p_data, uint32_t len);

#endif

#ifdef __cplusplus
}
#endif


