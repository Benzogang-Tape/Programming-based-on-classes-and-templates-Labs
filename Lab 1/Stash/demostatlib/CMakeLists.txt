cmake_minimum_required(VERSION 3.26)
project(demostatlib)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")



#include_directories("/mnt/d/BMSTU/Study/Course 1/Semester 2/Programming Basics/Labs/Libraries/Demostatlib/include")


add_executable(demostatlib main.cpp)

find_package(MyLib REQUIRED)
include_directories(${MYLIB_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${MYLIB_LIBRARY})

#find_library(TEST_LIBRARY libmylib.a "/mnt/d/BMSTU/Study/Course 1/Semester 2/Programming Basics/Labs/Libraries/Demostatlib/lib")
##find_library(STAT_LIBRARY libstatlib "D:/BMSTU/Study/Course 1/Semester 2/Programming Basics/Labs/Libraries/Demostatlib/lib")
#target_link_libraries(demostatlib LINK_PUBLIC ${TEST_LIBRARY})