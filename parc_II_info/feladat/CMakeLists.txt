cmake_minimum_required(VERSION 3.25)
project(feladat C)

set(CMAKE_C_STANDARD 23)

add_executable(feladat main.c sources/movie.c headers/movie.h sources/catalog.c headers/catalog.h)
include_directories(feladat headers)