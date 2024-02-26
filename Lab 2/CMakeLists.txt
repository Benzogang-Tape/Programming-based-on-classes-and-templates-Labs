cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Lab_2)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/PlanetsDB.txt
            ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/RoadsDB.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_subdirectory(Libraries)

include_directories(Libraries/Planet
                    Libraries/Road
                    Libraries/MenuInterface
                    Libraries/Database)

#include_directories(${PLANET_INCLUDE_DIR})
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(${PROJECT_NAME}_SOURCES
        main.cpp
        execution_modes.cpp)

set(${PROJECT_NAME}_HEADERS
        execution_modes.hpp)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES}
        ${${PROJECT_NAME}_HEADERS})

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_SOURCE_LIST})

target_link_libraries(${PROJECT_NAME} PRIVATE Planet)
target_link_libraries(${PROJECT_NAME} PRIVATE Road)
target_link_libraries(${PROJECT_NAME} PRIVATE MenuInterface)
target_link_libraries(${PROJECT_NAME} PRIVATE Database)
