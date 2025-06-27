#include <iostream>
#include <Windows.h>

int fibonacci(int value) {
    int first = 0;
    int second = 1;
    
    if (value == 1) {
        return first;
    }
    else if (value == 2) {
        return second;
    }
    else {
        for (int i = 2; i < value; ++i) {
            int temp = second;
            second += first;
            first = temp;
        }
        return first + second;
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
