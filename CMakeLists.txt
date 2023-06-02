cmake_minimum_required(VERSION 3.21)
project(Shakhmati LANGUAGES CXX)

file(GLOB_RECURSE MY_SOURCES "src/**.cpp")

add_executable(Shakhmati ${MY_SOURCES})

target_compile_features(Shakhmati PRIVATE cxx_std_20)

install(TARGETS Shakhmati)