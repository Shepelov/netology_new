#include <iostream>
#include <clocale>
#include <windows.h>

int fibonacci (int amount){
    if (amount == 1) return 0;
    if (amount == 2) return 1;
    return fibonacci(amount - 2) + fibonacci(amount - 1);
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int amount{};
    std::wcout << L"Введите целое число: ";
    std::cin >> amount;

    for (int i{1}; i <= amount; ++i){
        std::cout << fibonacci(i) << " ";
    }

    return 0;
}
