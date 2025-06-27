#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a)
		: Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {}
};

#endif