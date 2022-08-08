cmake_minimum_required(VERSION 3.23)
project(Travelling)

set(CMAKE_CXX_STANDARD 23)

add_executable(Travelling
    main.cpp main.h
    salesman/salesman.cpp salesman/salesman.h
)
