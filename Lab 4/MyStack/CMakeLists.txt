cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME MyStack)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(${PROJECT_NAME}_HEADERS
        MyStack.hpp
)

set(${PROJECT_NAME}_SOURCES
        MyStack.cpp
)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES}
        ${${PROJECT_NAME}_HEADERS}
)

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCE_LIST})