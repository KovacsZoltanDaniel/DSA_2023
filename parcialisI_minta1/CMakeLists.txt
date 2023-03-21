cmake_minimum_required(VERSION 3.23)
project(parcialisI_minta1 C)

set(CMAKE_C_STANDARD 23)

add_executable(parcialisI_minta1 main.c sources/patient.c headers/patient.h sources/medicalCenter.c headers/medicalCenter.h)
include_directories(parcialisI_minta1 headers)