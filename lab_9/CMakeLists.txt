cmake_minimum_required(VERSION 3.25)
project(lab_9 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_9 main.c headers/linked_list.h sources/linked_list.c)
include_directories(lab_9 headers)