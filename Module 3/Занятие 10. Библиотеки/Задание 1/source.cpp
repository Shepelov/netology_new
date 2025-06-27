#include <iostream>
#include <clocale>
#include <Windows.h>

#include "greeter.h"

int main(int argc, char* argv) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name;
	std::cout << "¬ведите им€: ";
	std::cin >> name;
	Greeter output;
	std::cout << output.greet(name) << std::endl;
}