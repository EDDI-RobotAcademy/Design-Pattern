cmake_minimum_required(VERSION 3.21)
project(c/ch2 C)

set(CMAKE_C_STANDARD 99)

add_executable(chapter2 main.c child_class.h parent_class.h parent_class.c child_class.c common.h)
