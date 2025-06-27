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

void print_info(Shape* shape) {
	shape->print_info();
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	Triangle trg(10, 20, 30, 40, 50, 60);
	print_info(&trg);
	RightTriangle rtrg(10, 20, 30, 50, 60);
	print_info(&rtrg);
	IsoscelesTriangle itrg(10, 20, 50, 60);
	print_info(&itrg);
	EquilateralTriangle etrg(30);
	print_info(&etrg);
	Quadangle qag(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&qag);
	Rectangle rect(10, 20);
	print_info(&rect);
	Square sqw(20);
	print_info(&sqw);
	Parallelogram prlg(20, 30, 30, 40);
	print_info(&prlg);
	Rhomb rhmb(30, 30, 40);
	print_info(&rhmb);
}