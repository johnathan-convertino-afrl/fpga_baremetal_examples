/***************************************************************************//**
  * @file     tft_vga.c
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

#include <stdlib.h>

#include "tft_vga.h"

// Initializes tft_vga structure and device
struct s_tft_vga *initTFTvga(uint32_t memory_address)
{
  struct s_tft_vga *p_temp = (struct s_uart *)memory_address;

  p_temp->base_addr   = 0;
  p_temp->control.reg = 0;
  p_temp->iesr.reg    = 0;
  p_temp->ccr.reg     = 0;
  p_temp->ext_base_addr_low   = 0;
  p_temp->ext_base_addr_high  = 0;

  return p_temp;
}
