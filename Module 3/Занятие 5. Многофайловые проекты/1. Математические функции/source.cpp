#include "math.h"

#include <clocale>
#include <iostream>

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	int value1;
	int value2;
	int operation;

	std::cout << "Введите число 1: ";
	std::cin >> value1;
	std::cout << "Введите число 2: ";
	std::cin >> value2;
	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> operation;

	switch (operation)
	{
	case 1:
		Math::summ(value1, value2);
		break;
	case 2:
		Math::diff(value1, value2);
		break;
	case 3:
		Math::mult(value1, value2);
		break;
	case 4:
		Math::div(value1, value2);
		break;
	case 5:
		Math::degr(value1, value2);
		break;
	}

	return 0;
}