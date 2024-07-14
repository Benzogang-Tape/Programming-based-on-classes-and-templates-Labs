cmake_minimum_required(VERSION 3.26)
project(mylib)

set(CMAKE_CXX_STANDARD 20)

add_library(mylib main.cpp libmylib.cpp)
