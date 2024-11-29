cmake_minimum_required(VERSION 3.29)
project(THDTYS C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(THDTYS
    board.c
    board.h
    bubble.c
    clock_config.c
    clock_config.h
    pin_mux.c
    pin_mux.h
    SPFD5408.c
    SPFD5408.h)
