cmake_minimum_required(VERSION 3.24)
project(vakacios_extra_8 C)

set(CMAKE_C_STANDARD 23)

add_executable(vakacios_extra_8 main.c sources/student.c headers/student.h)
include_directories(vakacios_extra_8 headers)