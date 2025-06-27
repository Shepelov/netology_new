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
    int value, summ{0}, dec{10};

    //запрос числа у пользователя
    std::wcout << L"Введите целое число: ";
    std::cin >> value;

    //логика программы
    while (value != 0){
        summ+=value%dec;
        value/=dec;
    }

    //вывод суммы цифр
    std::wcout << L"Сумма цифр: " << summ;

    return 0;
}
