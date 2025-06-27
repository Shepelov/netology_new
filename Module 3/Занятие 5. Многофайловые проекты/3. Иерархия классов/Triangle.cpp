#include "Triangle.h"

#include <iostream>

void Triangle::print_info() {
	std::cout << type << std::endl;
	std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << std::endl;
	std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
	std::cout << std::endl;
}