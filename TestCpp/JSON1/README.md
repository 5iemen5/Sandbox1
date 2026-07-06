# JSON1

## Abstract



## Description
---
Example of linking against cJSON library.

There's a lot of bs down here in this markdown. Cuz I tried to include mosquitto fucking library and failed. Im leaving this example as is


## NOTES

### (IGNORE) The paths, for copy and paste

`C:\Users\user\Documents\Libraries\cJSON`

`C:\Users\user\Documents\Libraries\mosquitto`

`C:\Users\user\Documents\Libraries\vcpkg\installed\x64-windows\lib\mosquitto.lib`

`C:\Program Files\Mosquitto`

### cJSON build (IGNORE. JSON IS NOT NEEDED 2 BUILD MOSQUITTO. CHOSEN vcpkg TO BUILD THE THING)  

1. `cmake -B build -G "MinGW Makefiles" -DBUILD_SHARED_AND_STATIC_LIBS=On`

OR (THIS SHIT IS ADIVCED because tests fail)

1. `cmake -B build -G "MinGW Makefiles"             \
                -DBUILD_SHARED_AND_STATIC_LIBS=On   \
                -DENABLE_CJSON_TEST=Off`            \`

2. `cd build`

3. `make` OR `mingw32-make.exe`

The next one required administrator rights.

4. Then `make install` OR `mingw32-make.exe install`

We got a static library file (*.a) in (3) and `Program Files (x86)` now contains a CMake-config file in (4).

`Program Files (x86)/cJSON/lib/cmake/cJSON/cJSONConfig.cmake`

Here's what happened:
CMake has a mechanism of including other libraries,
neccesary for a project, by using
`find_package(cJSON REQUIRED)`. It does look for a file 
that is conventionally named \<SomeLibrary\>Config.cmake
that comes as a product of building that library. It lists
some exported symbols and shit. 

To be short, there is no better way of linking other libraries
in a CMake project, and it's a standard.

Here is more info on this:
http://cmake.org/cmake/help/book/mastering-cmake/chapter/Finding%20Packages.html

---

### `make` vs `make install`

`make / mingw32-make.exe:`
Builds cJSON inside build/. Produces .a, .dll, .exe, etc. locally.

`make install` / `mingw32-make.exe install:`

Copies the built files to the install location, e.g. Program Files, including headers and cJSONConfig.cmake.

---

### Build Mosquitto (IGNORE. FAILED STRATEGY)

CMake options to set:
1. OPENSSL_INCLUDE_DIR
2. CJSON_INCLUDE_DIR
3. 

Tried building Mosquitto with 
`cmake -B build -DWITH_STATIC_LIBRARIES=ON -G "MinGW Makefiles"`

```
cmake -B build -DWITH_STATIC_LIBRARIES=ON  `
-G "MinGW Makefiles"       `  -DCJSON_INCLUDE_DIR="C:\\Users\\user\\Documents\\Libraries\\cJSON"
```
Still need to add pthread and ??? as dependencies

Pthread is at 
`C:\Users\user\Downloads\w64devkit\w64devkit\include`

### About Mosquitto build

I first wanted to build Mosquitto manually with raw CMake and MinGW so I could understand exactly what was being linked, maybe even keep a static Mosquitto library inside my own project.

That quickly led into dependency management: Mosquitto needs cJSON, OpenSSL, pthreads, and uthash. The awkward part was pthreads on Windows. Mosquitto’s CMake expects PThreads4W::PThreads4W, while my MinGW setup already had winpthreads through w64devkit, which is not the same CMake package target.

I downloaded pthreads4w and inspected its build system, but it was old makefile/autoconf-style rather than clean modern CMake. At that point, manual dependency setup was becoming more work than the actual Mosquitto integration.

I also realized vendoring a static libmosquitto binary is not ideal during development, since it depends on compiler, platform, build type, and dependency versions.

So I chose vcpkg. After installing MSVC Build Tools, vcpkg install mosquitto succeeded for x64-windows, installing Mosquitto plus OpenSSL, pthreads, and uthash automatically.

---


