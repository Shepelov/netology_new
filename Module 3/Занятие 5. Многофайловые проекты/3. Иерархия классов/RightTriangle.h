#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int A, int B, int C)
		: Triangle(a, b, 90, A, B, C, "Прямоугольный треугольник") {}
};

#endif