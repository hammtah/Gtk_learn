cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(untitled main.c
        Position.h)

target_link_libraries(untitled ${GTK3_LIBRARIES})