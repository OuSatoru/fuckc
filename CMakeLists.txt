cmake_minimum_required(VERSION 3.7)
project(fuckc)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES_fuck main.c)
set(SOURCE_FILES_sort sort/main.c)

add_executable(fuck ${SOURCE_FILES_fuck})
add_executable(sort ${SOURCE_FILES_sort})