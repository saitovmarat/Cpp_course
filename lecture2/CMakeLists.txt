cmake_minimum_required(VERSION 3.8)
project(sum500)

add_executable(sum500c sum500.c)
set_target_properties(
  sum500c PROPERTIES
  C_STANDARD 17
  C_STANDARD_REQUIRED ON
)


add_executable(sum500cpp sum500.cpp)
set_target_properties(
  sum500cpp PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
