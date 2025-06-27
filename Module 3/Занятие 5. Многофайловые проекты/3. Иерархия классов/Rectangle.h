#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Quadangle.h"

class Rectangle : public Quadangle {
public:
	Rectangle(int a, int b)
		: Quadangle(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {}
};

#endif