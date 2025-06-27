#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadangle.h"

class Parallelogram : public Quadangle {
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadangle(a, b, a, b, A, B, A, B, "Параллелограмм") {
		if (a != c && b != d) {
			throw GeometryException("Стороны a и c, b и d попарно не равны!");
		}
		else if (A != C && B != D) {
			throw GeometryException("Углы A и C, B и D попарно не равны!");
		}
		else {
			std::cout << "Параллелограмм (стороны: " << a << " " << b << " " << c << " " << d << ", углы: " << A << " " << B << " " << C << " " << D << ") создан" << std::endl;
		}
	}
};

#endif