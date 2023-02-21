cmake_minimum_required(VERSION 3.23)
project(feladat_45678 C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat_45678 src/main.c src/functions.c headers/functions.h)
include_directories(feladat_45678 headers)