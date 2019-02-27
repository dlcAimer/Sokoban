cmake_minimum_required(VERSION 3.10)
project(project)

set(CMAKE_CXX_STANDARD 11)

add_executable(project main.cpp board.cpp tools.cpp Timer.cpp game.cpp Rank.cpp AI.cpp)