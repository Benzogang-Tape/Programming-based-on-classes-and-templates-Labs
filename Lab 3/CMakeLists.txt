cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Lab_3)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(${PROJECT_NAME}_HEADERS
        Fraction.hpp
)

set(${PROJECT_NAME}_SOURCES
        Fraction.cpp
        main.cpp
)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES}
        ${${PROJECT_NAME}_HEADERS}
)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE_LIST})
