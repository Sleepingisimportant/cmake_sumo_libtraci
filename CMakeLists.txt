cmake_minimum_required(VERSION 3.15)
project(cmakeSumoLibtraci)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_VERBOSE_MAKEFILE ON)


# SUMO
# set SUMO_DIR to allow CMAKE to find SUMO (path: CMAKE build location in SUMO)
set(SUMO_DIR "${CMAKE_SOURCE_DIR}/sumo/build/CMAKE")

#check if CMAKE finds SUMO
find_package(SUMO REQUIRED)
if(SUMO_FOUND)
    message(STATUS "SUMO found.")
else()
    message(FATAL_ERROR "SUMO not found.")
endif()


# Add src files
file(GLOB SOURCES "src/*.**")
file(GLOB HEADERS "include/*.h")


add_executable(cmakeSumoLibtraci ${SOURCES} ${HEADERS})

#link SUMO libraries
target_link_libraries(cmakeSumoLibtraci PUBLIC SUMO::libtracicpp SUMO::libsumocpp)




