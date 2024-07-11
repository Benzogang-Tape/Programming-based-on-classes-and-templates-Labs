cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME  Planets)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(${PROJECT_NAME}_SOURCES
        Planet.cpp)

set(${PROJECT_NAME}_HEADERS
        Planet.hpp)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES}
        ${${PROJECT_NAME}_HEADERS})

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCE_LIST})