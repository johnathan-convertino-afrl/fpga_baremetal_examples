################################################################################
### date      2024.09.18
### author    Jay Convertino
### brief     Veronica Vexriscv examples
################################################################################

cmake_minimum_required(VERSION 3.14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/apps)

link_libraries(bare_metal_boot irq)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=${CMAKE_SYSTEM_PROCESSOR} -std=c99 -Os -g -Wall -Wextra -ffunction-sections ")

include_directories(${CMAKE_SOURCE_DIR}/src/drivers/)

if(BUILD_UART_EXAMPLES)
  #uart echo, polling method.
  add_executable(uart_echo.elf uart_echo.c)
  target_link_libraries(uart_echo.elf PRIVATE uart_drv)

  #uart echo, irq method
  add_executable(uart_echo_irq.elf uart_echo_irq.c)
  target_link_libraries(uart_echo_irq.elf PRIVATE uart_drv plic_drv timer_drv)

  #if needed
  #if(RISCV_GCC_COMPILER)
  #endif()

  # Post processing command to create a disassembly file
  add_custom_command(TARGET uart_echo_irq.elf POST_BUILD
          COMMAND ${CMAKE_OBJDUMP} -S  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/uart_echo_irq.elf > ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/uart_echo_irq.disasm
          COMMENT "Invoking: Disassemble")

  # Post processing command to create a hex file
  add_custom_command(TARGET uart_echo_irq.elf POST_BUILD
          COMMAND ${CMAKE_OBJCOPY} -O ihex  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/uart_echo_irq.elf  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/uart_echo_irq.hex
          COMMENT "Invoking: Hex dump")

  # Post processing command to create a hex file
  add_custom_command(TARGET uart_echo_irq.elf POST_BUILD
          COMMAND ${CMAKE_OBJCOPY} -O binary  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/uart_echo_irq.elf  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/uart_echo_irq.bin
          COMMENT "Invoking: Binary dump")
endif()

message(STATUS "Applications selected to build:")

get_property(target_names DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY BUILDSYSTEM_TARGETS)

foreach(app_name ${target_names})
  message(STATUS "* ${app_name}")
endforeach(app_name ${target_names})

set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)
