cmake_minimum_required(VERSION 3.21)
project(c/ch3 C)

set(CMAKE_C_STANDARD 99)

add_executable(chapter3 main.c child_class.h parent_class.h parent_class.c child_class.c common.h child_class2.c child_class2.h)
