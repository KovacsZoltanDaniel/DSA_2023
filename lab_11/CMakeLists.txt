cmake_minimum_required(VERSION 3.25)
project(lab_11 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_11 main.c sources/hash_table.c headers/hash_table.h)
include_directories(lab_11 headers)