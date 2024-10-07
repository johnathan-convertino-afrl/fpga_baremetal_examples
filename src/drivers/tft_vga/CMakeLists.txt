################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(TFT_VGA_DRV_SRCS
  tft_vga.c
  tft_vga.h
)

add_library(tft_vga_drv ${TFT_VGA_DRV_SRCS})
