cmake_minimum_required(VERSION 3.17)
project(List)

set(CMAKE_CXX_STANDARD 20)

add_executable(List main.cpp src/ListClass.cpp)  # Add ListClass.cpp here

target_include_directories(List PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/texts)
