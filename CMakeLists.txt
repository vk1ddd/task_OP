cmake_minimum_required(VERSION 3.28)
project(task_OP C)

set(CMAKE_C_STANDARD 11)

add_executable(task_OP main.c
        function/matrix_func.c
        function/matrix_func.h)
