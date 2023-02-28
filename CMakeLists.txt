cmake_minimum_required(VERSION 3.24)
project(CosaConSfml)

set(CMAKE_CXX_STANDARD 17)

link_directories(lib)
include_directories(include)

add_executable(CosaConSfml main.cpp)
target_link_libraries(CosaConSfml sfml-window sfml-graphics sfml-audio sfml-main sfml-system)
