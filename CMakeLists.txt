cmake_minimum_required(VERSION 3.8)
project(gomoku)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/pisqpipe.cpp src/example.cpp include/pisqpipe.h)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable(pbrain-gomoku ${SOURCE_FILES})