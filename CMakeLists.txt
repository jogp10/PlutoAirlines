cmake_minimum_required(VERSION 3.19.2)
project(PlutoAirlines)
set(CMAKE_CXX_STANDARD 14)

add_executable(PlutoAirlines main.cpp
        Airline/Airplane.cpp Airline/Airplane.h
        Airline/Passenger.cpp Airline/Passenger.h
        Airline/Ticket.h
        Airline/Luggage.h
        Airline/Flight.cpp Airline/Flight.h
        Airline/Airline.cpp Airline/Airline.h
        Airline/Airport.cpp Airline/Airport.h
        Airline/LandTransport.cpp
        Airline/Date.cpp Airline/Date.h
        Airline/Service.h
        Airline/bst.h
        Airline/LuggageTransport.cpp Airline/LuggageTransport.h
        App.cpp App.h

        Tests/AirlineTest.cpp
        Tests/AirplaneTest.cpp
        Tests/LuggageTest.cpp
        Tests/AirportTest.cpp
        Tests/TicketTest.cpp
        Tests/PassengerTest.cpp)


# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Airline")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)


# Google Tests

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

target_link_libraries(PlutoAirlines gtest gtest_main)