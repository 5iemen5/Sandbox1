# TestCpp

## Description
Example of circular shift right buffer                      \
This is where i tried Cpp function templates. Also here is  \
a vibecoded Timer lib - these are easy macros for           \
output of duration of program's runtime based on <chrono>   \

Run as `.\TestTemplates.exe 1 2 3`
If run as `.\TestTemplates.exe 1 2 3.0` program will terminate with code 5
Program must be fed values of same type: all integers, floats or strings.
Otherwise terminates.

---
## NOTES
Note CmakeLists: there are 2 ways to link against that      \
timer library; one option is commented, uses add_library()  \
target_include_directories() and target_link_libraries()    \



