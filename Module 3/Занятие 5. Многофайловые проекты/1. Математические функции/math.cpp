#include "math.h"

#include <iostream>
#include <string>

void Math::summ(int value1, int value2) {
	std::cout << std::to_string(value1) + " плюс " + std::to_string(value2) + " = " + std::to_string(value1 + value2);
}

void Math::diff(int value1, int value2) {
	std::cout << std::to_string(value1) + " минус " + std::to_string(value2) + " = " + std::to_string(value1 - value2);
}
void Math::mult(int value1, int value2) {
	std::cout << std::to_string(value1) + " умножить на " + std::to_string(value2) + " = " + std::to_string(value1 * value2);
}

void Math::div(int value1, int value2) {
	std::cout << std::to_string(value1) + " разделить на " + std::to_string(value2) + " = " + std::to_string(value1 / value2);
}

void Math::degr(int value1, int value2) {
	int result;
	if (value2 < 1) { result = 0; }
	else if (value2 == 1) { result = value1; }
	else {
		result = value1;
		for (int i = 1; i < value2; ++i) {
			result *= value1;
		}
	}

	std::cout << std::to_string(value1) + " в степени " + std::to_string(value2) + " = " + std::to_string(result);
}