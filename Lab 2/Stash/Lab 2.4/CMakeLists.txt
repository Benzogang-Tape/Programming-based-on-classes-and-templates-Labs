cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Lab_2_4)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

set(${PROJECT_NAME}_SOURCES
        main.cpp)

add_subdirectory(Planets)
add_subdirectory(Roads)

#[[
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dbase1.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dbase2.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
]]

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES})

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE_LIST})

target_link_libraries(${PROJECT_NAME} Planets)
target_link_libraries(${PROJECT_NAME} Roads)
