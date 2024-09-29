################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(GPIO_DRV_SRCS
  gpio.c
  gpio.h
)

add_library(gpio_drv ${GPIO_DRV_SRCS})
