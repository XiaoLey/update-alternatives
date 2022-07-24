cmake_minimum_required(VERSION 3.22)
project(update_alternatives C)

set(CMAKE_C_STANDARD 99)

add_executable(update_alternatives main.c parse_arg_list.cpp parse_arg_list.h)
