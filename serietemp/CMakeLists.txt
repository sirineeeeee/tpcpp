cmake_minimum_required(VERSION 3.26)
project(serietemp)

set(CMAKE_CXX_STANDARD 20)

add_executable(serietemp main.cpp  
        sin.cpp
        headers/sin.h
        stp.cpp
        headers/stp.h
        gau.cpp
        headers/gau.h
        tsdata.cpp
        headers/tsdata.h
        knn.cpp
        headers/knn.h
        tsgen.cpp
        headers/tsgen.h
)
