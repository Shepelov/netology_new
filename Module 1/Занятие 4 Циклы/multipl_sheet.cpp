#include <iostream>
#include <windows.h>
#include <clocale>

int main()
{
    //локализация
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    //объявляем переменные
    int value;

    //запрос числа у пользователя
    std::wcout << L"Введите целое число: ";
    std::cin >> value;

    //логика программы + вывод
    for (int i{1}; i < 11; ++i){
        std::cout << value << " x " << i << " = " << value*i << std::endl;
    }

    return 0;
}
