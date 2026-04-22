#!/bin/bash

# Check if a project name was provided
if [ -z "$1" ]; then
    echo "Error: Please provide a project name."
    echo "Usage: $(basename "$0") ProjectName"
    exit 1
fi

NAME="$1"

# 1. Create the folder structure
# The -p flag creates parent directories if they don't exist and suppresses errors if they do
echo "Creating directories for \"$NAME\"..."
mkdir -p "$NAME/src" "$NAME/include" "$NAME/build"

# 2. Create CMakeLists.txt
# Using EOF (without quotes) allows $NAME to be evaluated as a variable inside the text block
echo "Generating CMakeLists.txt..."
cat << EOF > "$NAME/CMakeLists.txt"
cmake_minimum_required(VERSION 3.23)

# Consider running  > cmake -B build -G "MinGW Makefiles"
# Or                > cmake -B build -G "Ninja"

set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_CXX_COMPILER "clang++")
#set(CMAKE_CXX_COMPILER "cl")

set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_C_COMPILER "cl")

project( $NAME )

add_executable( $NAME ./src/main.cpp include/main.h )

target_include_directories( $NAME PRIVATE include )
EOF

# 3. Create include/main.h
echo "Generating include/main.h..."
touch "$NAME/include/main.h"

# 4. Create src/main.cpp
# Using 'EOF' (with quotes) prevents bash from trying to evaluate anything inside the block
echo "Generating src/main.cpp..."
cat << 'EOF' > "$NAME/src/main.cpp"
#include "main.h"

int main() {
    
    return 0;
}
EOF

# 5. Create Template README.md
echo "Generating README.md..."
cat << EOF > "$NAME/README.md"
# $NAME

## Description
---


## NOTES
---

EOF

# 6. Create build clearing scripts
echo "Generating build removal scripts..."
cat << 'EOF' > "$NAME/sl_remove_build.sh"
#!/bin/bash
rm -rf build
mkdir build
EOF

# Make the Linux removal script executable by default
chmod +x "$NAME/sl_remove_build.sh"

cat << 'EOF' > "$NAME/sw_remove_build.bat"
@echo off
if exist build rd /s /q build
mkdir build
EOF

echo
echo "Project \"$NAME\" created successfully!"