cmake_minimum_required(VERSION 3.23)
project(bigints)

set(CMAKE_CXX_STANDARD 23)

add_executable(bigints
    main.h main.cpp
    sum/sum.h sum/sum.cpp
)
