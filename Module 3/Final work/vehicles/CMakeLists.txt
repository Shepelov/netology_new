cmake_minimum_required(VERSION 3.22.0)
project(Vehicles)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set (SOURCES 
	AirVehicle.cpp 
	Broom.cpp
	Eagle.cpp
	GroundVehicle.cpp
	MagicCarpet.cpp
	Vehicle.cpp
)
set (HEADERS 
	AirVehicle.h
	AllTerrainBoots.h
	Broom.h
	Camel.h
	Centaur.h
	Eagle.h
	FastCamel.h
	GroundVehicle.h
	MagicCarpet.h
	Vehicle.h 
)
add_library(Vehicles SHARED ${SOURCES} ${HEADERS})