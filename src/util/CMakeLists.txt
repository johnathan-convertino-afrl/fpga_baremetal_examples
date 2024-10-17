################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

if(BUILD_SDCARD_EXAMPLES OR BUILD_UTIL_FATFS)
  add_subdirectory(ff15)
endif()
