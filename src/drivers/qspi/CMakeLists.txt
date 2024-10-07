################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(QSPI_DRV_SRCS
  qspi.c
  qspi.h
)

add_library(qspi_drv ${QSPI_DRV_SRCS})
