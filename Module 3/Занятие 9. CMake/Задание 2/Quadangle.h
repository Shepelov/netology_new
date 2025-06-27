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
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: Shape(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string type)
		: Shape(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D), type(type) {}

	void print_info() override;
};
#endif