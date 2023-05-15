cmake_minimum_required(VERSION 3.25)
project(feladat_1 C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat_1 main.c sources/binary_tree.c headers/binary_tree.h)
include_directories(feladat_1 headers)