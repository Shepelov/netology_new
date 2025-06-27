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
	Triangle(int a, int b, int c, int A, int B, int C)
		: Shape(3), a(a), b(b), c(c), A(A), B(B), C(C) {}
	Triangle(int a, int b, int c, int A, int B, int C, std::string type)
		: Shape(3), a(a), b(b), c(c), A(A), B(B), C(C), type(type) {}

	void print_info() override;
};

#endif