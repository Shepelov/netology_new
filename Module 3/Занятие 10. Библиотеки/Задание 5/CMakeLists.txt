cmake_minimum_required(VERSION 3.22.0)
project(DLL_Test)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set (SOURCES 
	Quadangle.cpp 
	Triangle.cpp
)
set (HEADERS 
	Shape.h 
	Quadangle.h 
	Rectangle.h 
	Square.h 
	Rhomb.h 
	Parallelogram.h 
	Triangle.h
	EquilateralTriangle.h 
	IsoscelesTriangle.h 
	RightTriangle.h 
)
add_library(Shapes SHARED ${SOURCES} ${HEADERS})
add_executable(Client source.cpp)
target_link_libraries(Client Shapes)