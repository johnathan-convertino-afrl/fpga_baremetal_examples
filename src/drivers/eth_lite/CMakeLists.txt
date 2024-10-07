################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(ETH_LITE_DRV_SRCS
  eth_lite.c
  eth_lite.h
)

add_library(eth_lite_drv ${ETH_LITE_DRV_SRCS})
