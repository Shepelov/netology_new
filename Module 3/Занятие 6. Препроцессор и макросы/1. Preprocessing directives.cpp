#define MODE 12
#ifndef MODE
#error MODE not defined!
#endif

#if MODE == 0
#include <iostream>
#include <clocale>
int main(int argc, char argv[])
{
	setlocale(LC_ALL, "Rus");

	std::cout << "Работаю в режиме тренировки" << std::endl;
}

#elif MODE == 1
#include <iostream>
#include <clocale>
int add(int value1, int value2) {
	return value1 + value2;
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "Rus");

	int value1;
	int value2;
	std::cout << "Работаю в боевом режиме" << std::endl;
	std::cout << "Введите число 1: ";
	std::cin >> value1;
	std::cout << "Введите число 2: ";
	std::cin >> value2;
	std::cout << add(value1, value2);
}

#else
#include <iostream>
#include <clocale>
int main(int argc, char argv[])
{
	setlocale(LC_ALL, "Rus");

	std::cout << "Неизвестный режим. Завершение работы" << std::endl;
}
#endif