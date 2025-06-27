#include <iostream>
#include <clocale>
#include <Windows.h>

#include "leaver.h"

int main(int argc, char* argv) {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name;
	std::cout << "¬ведите им€: ";
	std::cin >> name;
	Leaver output;
	std::cout << output.leave(name) << std::endl;
}