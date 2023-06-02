cmake_minimum_required(VERSION 3.21)
project(Shakhmati LANGUAGES CXX)

file(GLOB_RECURSE MY_SOURCES "src/**.cpp")

add_executable(Shakhmati ${MY_SOURCES})

if(CMAKE_CXX_FLAGS_DEBUG)
    target_compile_options(Shakhmati PUBLIC -std=c++20 -O3 -march=native -mtune=generic)
else()
    target_compile_options(Shakhmati PUBLIC -std=c++20 -g -O0 -Wall -Wextra -pedantic -save-temps)
endif()

install(TARGETS Shakhmati)