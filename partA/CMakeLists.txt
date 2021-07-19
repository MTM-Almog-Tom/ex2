cmake_minimum_required(VERSION 3.0.0)
project(313151185_315155671)

set(CMAKE_CXX_STANDARD 11)

include_directories(partA)

# Define variables containing compiler flags for gcc
set(MTM_FLAGS_DEBUG "-std=c++11 -o -Wall --pedantic-errors -Werror -DNDEBUG --no-pie -I./ -IpartA")
set(MTM_FLAGS_RELEASE "${MTM_FLAGS_DEBUG} -DNDEBUG")

# Set the flags for gcc
set(CMAKE_CPP_FLAGS ${MTM_FLAGS_DEBUG})

add_executable(313151185_315155671
        part_a_test.cpp
        examDetails.h
        sortedList.h
        examDetails.cpp
        )