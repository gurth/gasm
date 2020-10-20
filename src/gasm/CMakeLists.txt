cmake_minimum_required(VERSION 3.15)
project(gasm)

set(CMAKE_CXX_STANDARD 14)

link_directories(../../lib)
include_directories("../../include")

add_executable(gasm main.cpp init.cpp translate.cpp translate.h error.cpp error.h process.cpp process.h register.c register.h presuffix.c)

target_link_libraries(gasm libreadline.so libyaml-cpp.so libasmjit.so libasmtk.so)


