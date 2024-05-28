cmake_minimum_required(VERSION 3.26)
project(TASK_6_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(TASK_6_2 main.cpp
        BaseEntity.h
        BaseEntity.cpp
        Stationary.h
        Stationary.cpp
        Movable.h
        Movable.cpp
        DynamicArray.h
        DynamicArray.cpp)
