#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Quadangle.h"

class Rectangle : public Quadangle {
public:
	Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadangle(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {
		if (a != c) {
			throw GeometryException("Стороны a и c не равны!");
		}
		else if (b != d) {
			throw GeometryException("Стороны b и d не равны!");
		}
		else if (A != 90 && B != 90 && C != 90 && D != 90) {
			throw GeometryException("Углы A, B, C и D не равны 90!");
		}
		else {
			std::cout << "Прямоугольник (стороны: " << a << " " << b << " " << c << " " << d << ", углы: " << A << " " << B << " " << C << " " << D << ") создан" << std::endl;
		}
	}
};

#endif