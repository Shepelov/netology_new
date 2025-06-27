#ifndef SQUARE_H
#define SQUARE_H

#include "Quadangle.h"

class Square : public Quadangle {
public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadangle(a, a, a, a, 90, 90, 90, 90, "Квадрат") {
		if (a != b && a != c && a != d) {
			throw GeometryException("Стороны a, b, c и d не равны друг другу!");
		}
		else if (A != 90 && B != 90 && C != 90 && D != 90) {
			throw GeometryException("Углы A, B, C и D не равны 90");
		}
		else {
			std::cout << "Квадрат (стороны: " << a << " " << b << " " << c << " " << d << ", углы: " << A << " " << B << " " << C << " " << D << ") создан" << std::endl;
		}
	}
};

#endif