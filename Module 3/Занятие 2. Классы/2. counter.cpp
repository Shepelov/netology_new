#include <iostream>
#include <clocale>

class Counter {
private:
	int value;
public:
	Counter() {
		value = 1;
	}

	Counter(int init) {
		value = init;
	}

	int increase() {
		value++;
		return value;
	}

	int decrease() {
		value--;
		return value;
	}

	int showValue() {
		return value;
	}
};

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	char start_initial;
	int init;
	Counter* cnt;
	char command;

	std::cout << "Вы хотите указать начальное значение счетчика? Введите \"Y\" или \"N\": ";
	std::cin >> start_initial;
	if (start_initial == 'Y') {
		std::cout << "Введите начальное значение счетчика (целое число): ";
		std::cin >> init;
		cnt = new Counter(init);
	}
	else {
		cnt = new Counter();
	}

	do {
		std::cout << "Введите команду (\"+\", \"-\", \"=\" или \"x\"): ";
		std::cin >> command;
		switch (command) {
		case 'x':
			break;
		case '+':
			std::cout << "Значение счетчика: " << cnt->increase() << std::endl << std::endl;
			break;
		case'-':
			std::cout << "Значение счетчика: " << cnt->decrease() << std::endl << std::endl;
			break;
		case '=':
			std::cout << "Значение счетчика: " << cnt->showValue() << std::endl << std::endl;
			break;
		default:
			std::cout << "Вы ввели некорректную команду!" << std::endl << std::endl;
			break;
		}
	} while (command != 'x');
	delete cnt;
	std::cout << "Работа программы завершена! До свидания!" << std::endl;

	return 0;
}

