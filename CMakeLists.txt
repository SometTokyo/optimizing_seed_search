cmake_minimum_required(VERSION 3.26)
project(researchalgo)

set(CMAKE_CXX_STANDARD 17)

add_executable(researchalgo main.cpp
        openfile.h
        openfile.cpp
        binary_ternary.cpp
        binary_ternary.h
        exponetial.cpp
        exponetial.h
        interpolation.cpp
        interpolation.h)
