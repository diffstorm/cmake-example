project(app)

add_executable(app src/main.cpp)

target_include_directories(app PRIVATE include)
target_link_libraries(app PRIVATE crc16)
