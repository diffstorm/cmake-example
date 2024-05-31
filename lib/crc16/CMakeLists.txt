project(crc16 C)

add_library(crc16 STATIC src/crc16.c)

target_include_directories(crc16 PUBLIC include)
