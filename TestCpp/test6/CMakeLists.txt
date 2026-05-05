cmake_minimum_required(VERSION 3.23)

# Consider running  > cmake -B build -G "MinGW Makefiles"
# Or                > cmake -B build -G "Ninja"

set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_COMPILER "cl")

set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_C_COMPILER "cl")

project( test6 )

add_executable( ${PROJECT_NAME} ./src/main.cpp include/main.h )

target_include_directories( ${PROJECT_NAME} PRIVATE include )
