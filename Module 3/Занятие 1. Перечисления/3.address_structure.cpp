#include <iostream>
#include <clocale>
#include <string>

struct Address {
	std::string city;
	std::string street;
	int house_n;
	int flat_n;
	int index;
};

void printAddress(const Address addr) {
	std::cout << "Город: " << addr.city << std::endl;
	std::cout << "Улица: " << addr.street << std::endl;
	std::cout << "Номер дома: " << addr.house_n << std::endl;
	std::cout << "Номер квартиры: " << addr.flat_n << std::endl;
	std::cout << "Индекс: " << addr.index << std::endl;
	std::cout << std::endl;
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	const Address first{ "Москва", "Арбат", 12, 8, 123456 };
	const Address second{"Ижевск", "Пушкина", 59, 143, 953769};

	printAddress(first);
	printAddress(second);

	return 0;
}