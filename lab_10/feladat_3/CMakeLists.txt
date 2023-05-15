cmake_minimum_required(VERSION 3.25)
project(feladat_3 C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat_3 main.c sources/bst_person.c headers/bst_person.h)
include_directories(feladat_3 headers)
