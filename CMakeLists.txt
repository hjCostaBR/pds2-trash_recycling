cmake_minimum_required(VERSION 3.12)
project(TrashRecycling)

set(CMAKE_CXX_STANDARD 14)
set(APP_TARGET "trash-recycling")

file(GLOB SRC_CODE_FILES
    GLOB_CPP_PATTERNS code/**/*.cpp
    GLOB_H_PATTERNS code/**/*.h
)

add_executable(${APP_TARGET} ${SRC_CODE_FILES})
target_compile_options(${APP_TARGET} PRIVATE -Wall -Wextra)