cmake_minimum_required(VERSION 3.21)

project(algorithms_4th CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_compile_options(
  -g
  -pedantic
  -pedantic-errors
  -Wall
  -Wextra
  -Werror
  -Wconversion)

add_subdirectory(src/ch01)
