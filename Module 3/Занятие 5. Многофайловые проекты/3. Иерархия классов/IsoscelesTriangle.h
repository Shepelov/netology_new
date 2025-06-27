#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H

#include "Triangle.h"

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {}
};

#endif