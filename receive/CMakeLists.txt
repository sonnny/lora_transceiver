cmake_minimum_required(VERSION 3.13)
include("/opt/pico-sdk/external/pico_sdk_import.cmake")
add_subdirectory(.. transceiver)
project(receive C CXX ASM)
pico_sdk_init()
add_executable(receive receive.cpp)
target_link_libraries(receive
  pico_stdlib
  sx1262lib
  )
pico_enable_stdio_usb(receive 1)
pico_add_extra_outputs(receive)
