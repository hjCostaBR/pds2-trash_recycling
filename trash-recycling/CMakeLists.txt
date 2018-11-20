cmake_minimum_required(VERSION 3.9.1)
project(TrashRecycling)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SRC_CODE_FILES
    GLOB_CPP_PATTERNS **/*.cpp
    GLOB_H_PATTERNS **/*.h
)

add_executable(trash-recycling ${SRC_CODE_FILES})