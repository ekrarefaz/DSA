cmake_minimum_required(VERSION 3.24)
project(MidTerm)

set(CMAKE_CXX_STANDARD 17)

add_executable(MidTerm main.cpp PrefixString.h PrefixString.cpp LZWTable.h LZWTable.cpp)
