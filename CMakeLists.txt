cmake_minimum_required(VERSION 3.19)
project(duplicate_checker)

set(CMAKE_CXX_STANDARD 20)

add_executable(duplicate_checker src/main.cpp src/LinkedList.cpp src/LinkedList.h src/Node.cpp src/Node.h)