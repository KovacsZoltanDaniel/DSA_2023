cmake_minimum_required(VERSION 3.25)
project(lab_10 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_10 main.c headers/bst_person.h sources/bst_person.c)
include_directories(lab_10 headers)