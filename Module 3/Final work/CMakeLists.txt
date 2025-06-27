cmake_minimum_required(VERSION 3.22.0)
project(RaceSimulator)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(vehicles)

add_executable(Simulator Source.cpp)
target_link_libraries(Simulator Vehicles)