cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Lab_2_3)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)


set(${PROJECT_NAME}_HEADERS
                )

set(${PROJECT_NAME}_SOURCES
        main.cpp)


add_subdirectory(Planet)
add_subdirectory(Product)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES})

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_SOURCE_LIST})

target_sources (${PROJECT_NAME} PRIVATE
        Planet/Planet.hpp
        Planet/Planet.cpp
        Product/Product.hpp
        Product/Product.cpp
)
