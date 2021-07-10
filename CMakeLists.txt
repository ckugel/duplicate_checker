cmake_minimum_required(VERSION 3.19)
project(duplicate_checker)

set(CMAKE_CXX_STANDARD 20)

add_executable(duplicate_checker main.cpp FileClass.cpp FileClass.h LinkedList.cpp LinkedList.h Node.cpp Node.h)