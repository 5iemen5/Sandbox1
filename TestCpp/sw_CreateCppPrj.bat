@echo off
setlocal

:: Check if a project name was provided
if "%~1"=="" (
    echo Error: Please provide a project name.
    echo Usage: %~nx0 ProjectName
    exit /b 1
)

set "NAME=%~1"

:: 1. Create the folder structure
echo Creating directories for "%NAME%"...
mkdir "%NAME%"
mkdir "%NAME%\src"
mkdir "%NAME%\include"
mkdir "%NAME%\build"

:: 2. Create CMakeLists.txt
echo Generating CMakeLists.txt...
(
echo cmake_minimum_required^(VERSION 3.23^)
echo.
echo # Consider running  ^> cmake -B build -G "MinGW Makefiles"
echo # Or                ^> cmake -B build -G "Ninja"
echo.
echo set^(CMAKE_CXX_COMPILER "g++"^)
echo #set^(CMAKE_CXX_COMPILER "clang++"^)
echo #set^(CMAKE_CXX_COMPILER "cl"^)
echo.
echo set^(CMAKE_C_COMPILER "gcc"^)
echo #set^(CMAKE_C_COMPILER "clang"^)
echo #set^(CMAKE_C_COMPILER "cl"^)
echo.
echo project^( %NAME% ^)
echo.
echo add_executable^( ${PROJECT_NAME} ./src/main.cpp include/main.h ^)
echo.
echo target_include_directories^( ${PROJECT_NAME} PRIVATE include ^)
) > "%NAME%\CMakeLists.txt"

:: 3. Create include/main.h
echo Generating include/main.h...
(
echo #pragma once
echo.
echo // Add declarations here
) > "%NAME%\include\main.h"

:: 4. Create src/main.cpp
echo Generating src/main.cpp...
(
echo #include "main.h"
echo.
echo int main^(^) {
echo.    
echo     return 0;
echo }
) > "%NAME%\src\main.cpp"

:: 5. Create Template README.md
echo Generating README.md...
(
echo # %NAME%
echo.
echo ## Description
echo ---
echo.
echo.
echo ## NOTES
echo ---
echo.
echo.
) > "%NAME%\README.md"

:: 6. Create utility scripts
echo Generating utility scripts...

:: Build removal scripts
(
echo #!/bin/bash
echo rm -rf build
echo mkdir build
) > "%NAME%\sl_remove_build.sh"

(
echo @echo off
echo if exist build rd /s /q build
echo mkdir build
) > "%NAME%\sw_remove_build.bat"

:: Project opening scripts
(
echo #!/bin/bash
echo code src/main.cpp include/main.h CMakeLists.txt
) > "%NAME%\sl_OpenPrj.sh"

(
echo @echo off
echo code src/main.cpp include/main.h CMakeLists.txt
) > "%NAME%\sw_OpenPrj.bat"

echo.
echo Project "%NAME%" created successfully!
endlocal