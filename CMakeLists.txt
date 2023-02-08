cmake_minimum_required(VERSION 3.17)
project(Sortedlist)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(sortedlist
        TestDriver.cpp
        SortedList.h)
