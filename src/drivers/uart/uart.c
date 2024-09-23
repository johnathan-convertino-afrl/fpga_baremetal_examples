/***************************************************************************//**
  * @file     uart.c
  * @brief    Xilinx AXI UART driver
  * @details  Baremetal C driver targeting Xilinx based UART lite cores.
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

#include <stdlib.h>

#include "uart.h"

// Initializes uart structure and device
inline struct s_uart *initUart(uint32_t memory_address)
{
  struct s_uart *p_temp = (struct s_uart *)memory_address;

  p_temp->tx_fifo     = 0;
  p_temp->status.reg  = 0;

  return p_temp;
}

// Read uart rx data
inline uint8_t getUartRxData(struct s_uart *p_uart)
{
  return (uint8_t)p_uart->rx_fifo;
}

// Write uart tx data
inline void setUartTxData(struct s_uart *p_uart, uint8_t data)
{
  p_uart->tx_fifo = (uint32_t)data;
}
