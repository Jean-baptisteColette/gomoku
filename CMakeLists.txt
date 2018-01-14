cmake_minimum_required(VERSION 3.8)	
project(gomoku)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/pisqpipe.cpp src/ia.cpp include/pisqpipe.h include/gomoku.h)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(pbrain-Plazza ${SOURCE_FILES})
