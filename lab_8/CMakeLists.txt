cmake_minimum_required(VERSION 3.23)
project(lab_8 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_8 main.c sources/linked.list.c headers/linked.list.h)
include_directories(lab_8 main.c headers)