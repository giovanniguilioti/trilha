cmake_minimum_required(VERSION 3.21)
project(trilha)

set(SOURCE_FILES 
        main.cpp
        trilha.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})