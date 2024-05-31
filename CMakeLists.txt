cmake_minimum_required(VERSION 3.10)
project(cmake_example VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add build types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;MinSizeRel" CACHE STRING "" FORCE)

# Include subdirectories
add_subdirectory(lib/crc16)
add_subdirectory(app)

