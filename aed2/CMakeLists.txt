cmake_minimum_required(VERSION 3.5)
project(aed2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Conj.h
    Dicc.h
    Dupla.h
    Lista.h
    TiposBasicos.h)

add_executable(aed2 ${SOURCE_FILES})