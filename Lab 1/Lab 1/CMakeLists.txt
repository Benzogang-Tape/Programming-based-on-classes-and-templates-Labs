cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME Lab_1)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)


set(${PROJECT_NAME}_SOURCES
        main.cpp)

add_subdirectory(mymath)
add_subdirectory(MyLib)

set(${PROJECT_NAME}_SOURCE_LIST
        ${${PROJECT_NAME}_SOURCES})

add_executable(${PROJECT_NAME}
        ${${PROJECT_NAME}_SOURCE_LIST})

target_link_libraries(${PROJECT_NAME} mymath)
target_link_libraries(${PROJECT_NAME} MyLib)
