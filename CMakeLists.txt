cmake_minimum_required(VERSION 3.27)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        retangulo.h
        plano.h
        menu.h
        menu.c
        plano.c
        rectangle.c)
