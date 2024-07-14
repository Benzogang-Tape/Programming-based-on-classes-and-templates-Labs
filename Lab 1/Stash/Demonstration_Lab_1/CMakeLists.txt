cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Demonstration_Lab_1)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(${PROJECT_NAME}_SOURCES
        main.cpp)

set(STATIC_LIB "/mnt/d/BMSTU/Study/Course 1/Semester 2/Programming Basics/Labs/Static_Library")

include_directories(STATIC_LIB)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES})

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_SOURCE_LIST})

target_link_libraries(${PROJECT_NAME} STATIC_LIB)
