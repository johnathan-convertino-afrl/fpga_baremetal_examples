################################################################################
### date      2024.09.18
### author    Jay Convertino
################################################################################

cmake_minimum_required(VERSION 3.14)

add_subdirectory(plic)
add_subdirectory(timer)

if(BUILD_UART_EXAMPLES OR BUILD_DRV_UART)
  add_subdirectory(uart)
endif()
