cmake_minimum_required(VERSION 3.13)
project(Os)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_SOURCE_FILE_EXTENSIONS main.c testfunc.c minitest.c)
add_executable(Os
#        main.c
#        minitest.c
#        testfunc.c
#        fileinput.c
        FCFS.c)