#include <iostream>
#include <Windows.h>

int fibonacci(int value) {
    if (value == 1) {
        return 0;
    }
    else if (value == 2) {
        return 1;
    }
    else {
        return fibonacci(value - 2) + fibonacci(value - 1);
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    //входные данные
    int value;

    std::cout << "Программа для расчета чисел Фибоначчи." << std::endl << std::endl;;
    do {
        std::cout << "Введите номер числа в ряду (для выхода из программы введите 0): ";
        std::cin >> value;
        if (value < 1) {
            break;
        }
        std::cout << "Значение " << value << " числа в ряду Фибоначчи - " << fibonacci(value) << std::endl;
    } while (value != 0);
    
}
