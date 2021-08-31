cmake_minimum_required(VERSION 3.20)
project(painlog VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_library(painlog SHARED painlog/structs.c painlog/sinks/file_sink.c painlog/sinks/file_sink.h painlog/painlog.h)
target_compile_definitions(painlog PRIVATE BUILD_SHARED)
