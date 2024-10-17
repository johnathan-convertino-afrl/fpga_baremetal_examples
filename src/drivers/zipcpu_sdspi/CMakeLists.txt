################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(ZIPCPU_SDSPI_DRV_SRCS
  diskio.c
  diskiodrvr.h
  emmcdrv.c
  emmcdrv.h
  sdiodrv.c
  sdiodrv.h
  sdspidrv.c
  sdspidrv.h
)

add_library(zipcpu_sdspi_drv ${ZIPCPU_SDSPI_DRV_SRCS})
