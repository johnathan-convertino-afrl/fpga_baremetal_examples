################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(TIMER_DRV_SRCS
  timer.c
  timer.h
)

add_library(timer_drv ${TIMER_DRV_SRCS})
