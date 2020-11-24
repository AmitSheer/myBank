cmake_minimum_required(VERSION 3.13)  # CMake version check
project(myBank)               # Create project "simple_example"
set(CMAKE_C_STANDARD 99)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.c)
#set(LIBRARY myBank.c libmyBank.a)
add_library(libmyBank STATIC myBank.c)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})

target_link_libraries(main LINK_PUBLIC libmyBank)