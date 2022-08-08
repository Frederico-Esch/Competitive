cmake_minimum_required(VERSION 3.23)
project(bitwise)

set(CMAKE_CXX_STANDARD 23)

add_executable(bitwise
    main.cpp main.h
    sorting/sort.cpp sorting/sort.h
    longest/longest.cpp longest/longest.h
    hamming/hamming.cpp hamming/hamming.h
    3NP1/3NP1.cpp 3NP1/3NP1.h
    substring/substring.cpp substring/substring.h
    score/score.h score/score.cpp
    andtuples/andtuples.h andtuples/andtuples.cpp
)
