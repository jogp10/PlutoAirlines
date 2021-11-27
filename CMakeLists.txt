cmake_minimum_required(VERSION 3.19.2)
project(PlutoAirlines)

set(CMAKE_CXX_STANDARD 14)

add_executable(PlutoAirlines main.cpp cmake-build-debug/Passenger.cpp cmake-build-debug/Passenger.h)
