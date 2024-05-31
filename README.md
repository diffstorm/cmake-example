# CMake Example

[![Build Status](https://github.com/diffstorm/cmake-example/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/diffstorm/cmake-example/actions)
[![License](https://img.shields.io/github/license/diffstorm/cmake-example)](https://github.com/diffstorm/cmake-example/blob/main/LICENSE)
[![Language](https://img.shields.io/github/languages/top/diffstorm/cmake-example)](https://github.com/diffstorm/cmake-example)

Reusable example CMake setup for C/C++ projects.

This is a simple example project to demonstrate a reusable CMake setup with a C++ application and a C library.

## Directory Structure
```
cmake-example/
+-- CMakeLists.txt
+-- app/
¦   +-- CMakeLists.txt
¦   +-- include/
¦   ¦   +-- app.hpp
¦   +-- src/
¦       +-- main.cpp
+-- lib/
¦   +-- crc16/
¦       +-- CMakeLists.txt
¦       +-- include/
¦       ¦   +-- crc16.h
¦       +-- src/
¦           +-- crc16.c
+-- README.md
```

## What is CMake?

CMake is an open-source, cross-platform family of tools designed to build, test, and package software. CMake is used to control the software compilation process using simple platform and compiler-independent configuration files, and it generates native makefiles and workspaces that can be used in the compiler environment of your choice.

## Installing CMake

### On Ubuntu

To install CMake on Ubuntu, you can use the package manager:

```sh
sudo apt update
sudo apt install cmake
```

### On Windows

To install CMake on Windows, follow these steps:

1. Go to the CMake download page.
2. Download the Windows installer (e.g., `cmake-<version>-windows-x86_64.msi`).
3. Run the installer and follow the on-screen instructions.

After installation, make sure to add CMake to your system's PATH during the installation process, or manually add the CMake `bin` directory to your PATH environment variable.

## Building the Project

### Clone the Repository

First, clone the repository:
```sh
git clone https://github.com/diffstorm/cmake-example.git
cd cmake-example
```

### Create a Build Directory

Create a directory to hold the build files:
```sh
mkdir build
cd build
```

### Configure the Project

Run CMake to configure the project:
```sh
cmake ..
```

### Build the Project

Compile the project using CMake:
```sh
cmake --build .
```

## Build Types

CMake supports different build types. The main build types are:

- `Debug`: Includes debug information and disables optimization.
- `Release`: Includes optimization but no debug information.
- `MinSizeRel`: Optimizes for the smallest binary size.

### Specify a Build Type

You can specify the build type when configuring the project. For example, to use the Debug build type:
```sh
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

For a `Release` build type:
```sh
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

For a `MinSizeRel` build type:
```sh
cmake -DCMAKE_BUILD_TYPE=MinSizeRel ..
cmake --build .
```

## Running the Application

After building the project, you can run the application. Use the `--file` or `-f` argument to specify the file for which you want to calculate the CRC16-CCITT checksum.
```sh
./app --file <filename>
```
or
```sh
./app -f <filename>
```
This will calculate the CRC16-CCITT checksum of the specified file.

## Usage Log

```sh
$ git clone https://github.com/diffstorm/cmake-example.git

$ cd cmake-example

cmake-example$ mkdir build

cmake-example$ cd build/

cmake-example/build$ cmake ..
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: cmake-example/build

cmake-example/build$ cmake --build .
[ 25%] Building C object lib/crc16/CMakeFiles/crc16.dir/src/crc16.c.o
[ 50%] Linking C static library libcrc16.a
[ 50%] Built target crc16
[ 75%] Building CXX object app/CMakeFiles/app.dir/src/main.cpp.o
[100%] Linking CXX executable app
[100%] Built target app

cmake-example/build$ ./app/app -f CMakeCache.txt
CRC16-CCITT of file CMakeCache.txt is 6cfb

cmake-example/build$ ./app/app -v
App version 1.0

cmake-example/build$ ./app/app -h
Usage: app [options]
Options:
  --file, -f <filename>   Calculate CRC16-CCITT of the specified file
  --help, -h              Show this help message
  --version, -v           Show version information
```

## :snowman: Author

Eray Öztürk ([@diffstorm](https://github.com/diffstorm))
