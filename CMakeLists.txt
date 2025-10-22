cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(Main)

pico_sdk_init()

add_executable(Main
    main.c
    mpu6050.c
)

target_link_libraries(Main
    pico_stdlib
    hardware_i2c
)

pico_enable_stdio_usb(Main 1)
pico_enable_stdio_uart(Main 0)

pico_add_extra_outputs(Main)