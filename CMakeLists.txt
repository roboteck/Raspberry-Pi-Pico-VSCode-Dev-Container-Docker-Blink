cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
#     message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
# endif()

# Initialize the SDK
pico_sdk_init()

add_executable(${PROJECT_NAME}
        blink.c
        )

        
# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

        
# pull in common dependencies
target_link_libraries(${PROJECT_NAME}
        pico_stdlib

        )

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)
