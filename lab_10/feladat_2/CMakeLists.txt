cmake_minimum_required(VERSION 3.25)
project(feladat_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat_2 main.c sources/bst.c headers/bst.h)
include_directories(feladat_2 headers)