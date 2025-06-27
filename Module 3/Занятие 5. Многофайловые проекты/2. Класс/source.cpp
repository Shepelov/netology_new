#include "Counter.h"

#include <clocale>
#include <iostream>

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	char command{};
	int initial;
	Counter cnt;

	std::cout << "Вы хотите указать начальное значение счётчика? (y/n): ";
	std::cin >> command;
	if (command == 'y') {
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> initial;
		cnt.setStartValue(initial);
	}

	do {
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> command;
		switch (command)
		{
		case '+':
			cnt.increase();
			break;
		case '-':
			cnt.decrease();
			break;
		case '=':
			cnt.show();
			break;
		}
	} while (command != 'x');

	std::cout << "Работа программы завершена! До свидания!";

	return 0;
}