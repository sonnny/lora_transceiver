cmake_minimum_required(VERSION 3.13)
include("/opt/pico-sdk/external/pico_sdk_import.cmake")
add_subdirectory(.. lora_transceiver)
project(transceiver C CXX ASM)
pico_sdk_init()
add_executable(transceiver transceiver.cpp)
target_link_libraries(transceiver
  pico_stdlib
  pico_rand
  sx1262lib
  )
pico_enable_stdio_usb(transceiver 1)
pico_add_extra_outputs(transceiver)
