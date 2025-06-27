#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

#include <string>

class Triangle : public Shape
{
private:
	std::string type{ "Треугольник" };
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
public:
	Triangle(int a, int b, int c, int A, int B, int C) : Shape(3) {
		if (A + B + C != 180) {
			throw GeometryException("Сумма углов не равна 180!");
		}
		else {
			this->a = a;
			this->b = b;
			this->c = c;
			this->A = A;
			this->B = B;
			this->C = C;
			std::cout << "Треугольник (стороны: " << a << " " << b << " " << c << ", углы: " << A << " " << B << " " << C << ") создан" << std::endl;
		}
	}
	Triangle(int a, int b, int c, int A, int B, int C, std::string type) : Shape(3) {
		if (A + B + C != 180) {
			throw GeometryException("Сумма углов не равна 180!");
		}
		else {
			this->a = a;
			this->b = b;
			this->c = c;
			this->A = A;
			this->B = B;
			this->C = C;
			this->type = type;
		}
	}

	void print_info() override;
};

#endif