cmake_minimum_required(VERSION 3.25)
project(feladat_4 C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat_4 main.c sources/bs_tree.c headers/bs_tree.h ../../lab_11/sources/hash_table.c ../../lab_11/headers/hash_table.h)
include_directories(feladat_4 headers)