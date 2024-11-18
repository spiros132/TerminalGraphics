cmake_minimum_required(VERSION 3.30.0)
project(TerminalGraphics VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_subdirectory(src)

add_subdirectory(test)