cmake_minimum_required(VERSION 3.23)
project(lab_4 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_4 main.c src/array.c headers/array.h)
include_directories(lab_4 headers)
