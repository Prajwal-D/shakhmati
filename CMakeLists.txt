cmake_minimum_required(VERSION 3.21)
project(Shakhmati LANGUAGES CXX)

file(GLOB_RECURSE MY_SOURCES "src/**.cpp")

if(CMAKE_CXX_FLAGS_DEBUG)
    set_source_files_properties(${MY_SOURCES} PROPERTIES COMPILE_OPTIONS "-std=c++20;-g;-O0;-Wall;-Wextra;-Wpedantic;-save-temps")
else()
    set_source_files_properties(${MY_SOURCES} PROPERTIES COMPILE_OPTIONS "-std=c++20;-O3;-march=native;-mtune=generic;-save-temps")
endif()

add_executable(Shakhmati ${MY_SOURCES})


install(TARGETS Shakhmati)