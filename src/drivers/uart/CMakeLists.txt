################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(UART_DRV_SRCS
  uart.c
  uart.h
)

add_library(uart_drv ${UART_DRV_SRCS})
