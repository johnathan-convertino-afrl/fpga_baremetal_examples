################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

set(FATFS_UTIL_SRCS
  source/diskio.h
  source/ff.c
  source/ff.h
  source/ffconf.h
  source/ffsystem.c
  source/ffunicode.c
)

add_library(fatfs_util ${FATFS_UTIL_SRCS})
