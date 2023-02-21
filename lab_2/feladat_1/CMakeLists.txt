cmake_minimum_required(VERSION 3.23)
project(feladat_1 C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat_1 src/main.c src/functions.matrix.c headers/functions.matrix.h headers/constant.h)
include_directories(feladat_1 headers)