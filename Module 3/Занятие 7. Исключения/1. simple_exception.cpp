#include <iostream>
#include <clocale>
#include <Windows.h>

class Bad_length : public std::exception {
public:
	const char* what() const override {
		return "Вы ввели слово запретной длины! До свидания!";
	}
};

int function(std::string str, int forbidden_length) {
	if (str.size() != forbidden_length) {
		return str.size();
	}
	else {
		throw Bad_length();
	}
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int forbidden_length;
	std::string word;

	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;
	do {
		try {
			std::cout << "Введите слово: ";
			std::cin >> word;
			std::cout << "Длина слова \"" << word << "\" равна " << function(word, forbidden_length) << std::endl;
		}
		catch (const Bad_length& ex) {
			std::cout << ex.what() << std::endl;
			exit(0);
		}
	} while (true);
	

	return 0;
}