# this file is not ready for use yet.
# use the supplied Makefile for now.

cmake_minimum_required(VERSION 3.5)
project(sdpbuffer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

#include_directories(src SyDEVSbase)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURREND_BINARY_DIR}/../../sydevs/src/)
set(LINK_LIBS ${LINK_LIBS} ../../sydev/src)

set(SOURCE_FILES
	main.cpp)


add_executable(skabuffer ${SOURCE_FILES})
