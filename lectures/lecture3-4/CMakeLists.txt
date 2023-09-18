cmake_minimum_required(VERSION 3.8)
project(matrix)

add_executable(matrix matrix.cpp)
set_target_properties(
  matrix PROPERTIES
  C_STANDARD 17
  C_STANDARD_REQUIRED ON
)
