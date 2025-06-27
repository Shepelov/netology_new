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
    int value, summ{0};

    //ввод-вывод + логика программы
    do{
        std::wcout << L"Введите целое число или \"0\", чтобы вывести сумму: ";
        std::cin >> value;
        summ+=value;
    }
    while (value != 0);

    //вывод суммы
    std::wcout << L"Сумма введенных чисел: " << summ << std::endl;

    return 0;
}
