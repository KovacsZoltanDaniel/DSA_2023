cmake_minimum_required(VERSION 3.23)
project(lab_3 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_3 main.c src/student.c headers/student.h src/product.c headers/product.h)
include_directories(lab_3 headers)