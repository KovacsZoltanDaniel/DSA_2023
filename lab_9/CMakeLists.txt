cmake_minimum_required(VERSION 3.25)
project(lab_9 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_9 main.c sources/linkedd_list.c headers/linkedd_list.h)
include_directories(lab_9 headers)