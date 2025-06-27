#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {
		if (a != b && a != c) {
			throw GeometryException("Стороны a, b и c не равны друг другу!");
		}
		else if (A != 60 && B != 60 && C != 60) {
			throw GeometryException("Углы A, B и C не равны 60!");
		}
		else {
			std::cout << "Равносторонный треугольник (стороны: " << a << " " << b << " " << c << ", углы: " << A << " " << B << " " << C << ") создан" << std::endl;
		}
	}
};

#endif