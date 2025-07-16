cmake_minimum_required(VERSION 3.13)
include("/opt/pico-sdk/external/pico_sdk_import.cmake")
project(sx1262lib C CXX ASM)
pico_sdk_init()

add_library(sx1262lib
  sx1262/Lora.cpp
  sx1262/sx126x_hal.c
  sx1262/sx126x.c
  )

target_include_directories(sx1262lib PUBLIC  ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(sx1262lib PRIVATE ${CMAKE_CURRENT_LIST_DIR}/sx1262)

target_link_libraries(sx1262lib
  pico_stdlib
  hardware_spi
  hardware_gpio
  )
