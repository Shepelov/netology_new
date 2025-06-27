#include <iostream>
#include <clocale>
#include <Windows.h>
#include <string>

struct Account {
	int number;
	std::string name;
	double balance;
};

void printAccount(Account* acc) {
	std::cout << "Ваш счет: " << acc->name << ", " << acc->number << ", " << acc->balance << std::endl;
}

void changeBalance(Account* acc, double new_balance) {
	acc->balance = new_balance;
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Account acc;
	double new_balance;

	std::cout << "Введите номер счета: ";
	std::cin >> acc.number;
	std::cout << "Введите имя: ";
	std::cin >> acc.name;
	std::cout << "Введите баланс: ";
	std::cin >> acc.balance;
	printAccount(&acc);
	std::cout << "Введите новый баланс: ";
	std::cin >> new_balance;
	changeBalance(&acc, new_balance);
	printAccount(&acc);

	return 0;
}