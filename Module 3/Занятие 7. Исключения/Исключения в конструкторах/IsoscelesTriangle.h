#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {
		if (a != c) {
			throw GeometryException("Стороны a и c не равны!");
		}
		else if (A != C) {
			throw GeometryException("Углы A и C не равны!");
		}
		else {
			std::cout << "Равнобедренный треугольник (стороны: " << a << " " << b << " " << c << ", углы: " << A << " " << B << " " << C << ") создан" << std::endl;
		}
	}
};

#endif