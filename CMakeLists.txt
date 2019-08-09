cmake_minimum_required(VERSION 3.5.1)
project(leveldb)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR})
file(GLOB SRCS ${CMAKE_SOURCE_DIR}/src/leveldb/*.cpp)


add_definitions(-std=c++11)
add_library(leveldb ${SRCS})

add_subdirectory(test)


