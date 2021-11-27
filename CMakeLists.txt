cmake_minimum_required(VERSION 3.19.2)
project(PlutoAirlines)
set(CMAKE_CXX_STANDARD 14)

add_executable(PlutoAirlines main.cpp Airline/Airplane.cpp Airline/Airplane.h Airline/Passenger.cpp Airline/Passenger.h Airline/Luggage.cpp Airline/Luggage.h)

