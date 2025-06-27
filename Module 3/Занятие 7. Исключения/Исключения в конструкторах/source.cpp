#include <iostream>
#include <clocale>

#include "Shape.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");
	
	try {
		Triangle trg(10, 20, 30, 70, 50, 60);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}
	
	try {
		RightTriangle trg(10, 20, 30, 70, 50, 60);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}

	try {
		IsoscelesTriangle trg(10, 20, 30, 70, 50, 60);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}

	try {
		EquilateralTriangle trg(10, 20, 30, 70, 50, 60);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}

	try {
		Quadangle trg(10, 20, 30, 40, 90, 90, 90, 90);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}

	try {
		Rectangle trg(10, 20, 30, 40, 90, 90, 90, 90);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}

	try {
		Square trg(10, 20, 30, 40, 90, 90, 90, 90);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}

	try {
		Parallelogram trg(10, 20, 30, 40, 90, 90, 90, 90);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}

	try {
		Rhomb trg(10, 20, 30, 40, 90, 90, 90, 90);
	}
	catch (GeometryException& ex) {
		std::cout << "Фигура не создана! Причина: ";
		std::cout << ex.what() << std::endl;
	}
}