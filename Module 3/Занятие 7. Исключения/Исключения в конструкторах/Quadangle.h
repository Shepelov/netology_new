#ifndef QUADANGLE_H
#define QUADANGLE_H
#include "Shape.h"

#include <string>
class Quadangle : public Shape
{
private:
	std::string type{ "Четырехугольник" };
	int a;
	int b;
	int c;
	int d;
	int A;
	int B;
	int C;
	int D;
public:
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D) : Shape(4) {
		if (A + B + C + D != 360) {
			throw GeometryException("Сумма углов не равна 360!");
		}
		else {
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
			this->A = A;
			this->B = B;
			this->C = C;
			this->D = D;
			std::cout << "Четырехугольник (стороны: " << a << " " << b << " " << c << " " << d << ", углы: " << A << " " << B << " " << C << " " << D << ") создан" << std::endl;
		}
	}
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string type) : Shape(4) {
		if (A + B + C + D != 360) {
			throw GeometryException("Сумма углов не равна 360!");
		}
		else {
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
			this->A = A;
			this->B = B;
			this->C = C;
			this->D = D;
			this->type = type;
		}
	}

	void print_info() override;
};
#endif