cmake_minimum_required(VERSION 3.23)

option(DONOTHING "TEMP OPTION: DO NOTHING, DON'T COMPILE" 0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(cjson_include_path "C:/Users/user/Documents/Libraries/cjson")
set(cjson_lib_path "C:/Users/user/Documents/Libraries/cjson/build/libcjson.a")

if(OPTION1)

else()

#===========================================================

# Consider running  > cmake -B build -G "MinGW Makefiles"
# Or                > cmake -B build -G "Ninja"

set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_COMPILER "cl")

set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_C_COMPILER "cl")

project( JSON1 )

add_executable( ${PROJECT_NAME} ./src/main.cpp include/main.hpp )

target_include_directories( ${PROJECT_NAME} PRIVATE include )

#===========================================================

# Add JSON precompiled shared library
message("-- Linking cJSON")

target_include_directories(${PROJECT_NAME} PRIVATE ${cjson_include_path})

target_link_libraries(${PROJECT_NAME} ${cjson_lib_path})

endif()
