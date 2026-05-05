cmake_minimum_required(VERSION 3.23)

# Consider running  > cmake -B build -G "MinGW Makefiles"
# Or                > cmake -B build -G "Ninja"

set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_COMPILER "cl")

set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_C_COMPILER "cl")

project( TestTemplates )

# add_library( TimerLib STATIC ./src/MultiTimer.cpp )
# target_include_directories( TimerLib PUBLIC include )

add_executable( ${PROJECT_NAME} 
    ./src/main.cpp 
    ./src/MultiTimer.cpp
    include/main.hpp 
    include/MultiTimer.hpp
)


#target_link_libraries( ${PROJECT_NAME} PRIVATE TimerLib )

target_include_directories( ${PROJECT_NAME} PRIVATE include )


project( TestTemplates )