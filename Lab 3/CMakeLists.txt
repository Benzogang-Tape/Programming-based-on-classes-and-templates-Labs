cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Lab_3)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Libraries)

include_directories(Libraries/Fraction)

#include_directories(${PLANET_INCLUDE_DIR})
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(${PROJECT_NAME}_SOURCES
        main.cpp)

#set(${PROJECT_NAME}_HEADERS
#        execution_modes.hpp)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES}
        ${${PROJECT_NAME}_HEADERS})

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_SOURCE_LIST})

target_link_libraries(${PROJECT_NAME} PRIVATE Fraction)
