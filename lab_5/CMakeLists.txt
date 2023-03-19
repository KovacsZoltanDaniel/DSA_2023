cmake_minimum_required(VERSION 3.23)
project(lab_5 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_5 main.c sources/stack.c headers/stack.h sources/regular_queue.c headers/regular_queue.h)
include_directories(lab_5 headers)