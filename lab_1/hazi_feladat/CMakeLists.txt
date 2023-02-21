cmake_minimum_required(VERSION 3.23)
project(hazi_feladat C)

set(CMAKE_C_STANDARD 23)

add_executable(hazi_feladat src/main.c src/functions.c header/functions.h)
include_directories(hazi_feladat header)
