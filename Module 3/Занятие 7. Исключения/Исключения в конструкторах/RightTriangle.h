#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, 90, A, B, C, "Прямоугольный треугольник") {
		if (C != 90) {
			throw GeometryException("Угол C не равен 90!");
		}
		else {
			std::cout << "Прямоугольный треугольник (стороны: " << a << " " << b << " " << c << ", углы: " << A << " " << B << " " << C << ") создан" << std::endl;
		}
	}
};

#endif