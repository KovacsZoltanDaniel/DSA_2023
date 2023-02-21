cmake_minimum_required(VERSION 3.23)
project(feladat_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat_2 Src/main.c Src/functions.c Headers/functions.h)
include_directories(feladat_2 Headers)