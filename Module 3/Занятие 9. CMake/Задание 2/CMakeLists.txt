cmake_minimum_required(VERSION 3.22.0)
project(my_first_cmake_project)

add_executable(my_first_cmake_program 
	source.cpp
	Shape.h
	Quadangle.h
	Quadangle.cpp
	Rectangle.h
	Rhomb.h
	Square.h
	Triangle.h
	Triangle.cpp
	EquilateralTriangle.h
	IsoscelesTriangle.h
	RightTriangle.h)