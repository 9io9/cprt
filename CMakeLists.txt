cmake_minimum_required(VERSION 3.28)
project(cprt C)

set(CMAKE_C_STANDARD 17)

set(BUILD_SHARED_LIBS off)

add_library(cprt cprt.c cprt.err.h cprt.def.h cprt.h)
