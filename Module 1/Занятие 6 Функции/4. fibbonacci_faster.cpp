#include <iostream>
#include <clocale>
#include <windows.h>

void fibSequence (int amount){
    if(amount > 0) std::cout << "0 ";
    if(amount > 1) std::cout << "1 ";
    if(amount > 2){
        long long prevInt{1};
        long long prevPrevInt{0};
        for (int i{3}; i <= amount; ++i){
            long long temp = prevInt;
            prevInt += prevPrevInt;
            prevPrevInt = temp;
            std::cout << prevInt << " ";

        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int amount{};
    std::wcout << L"Введите целое число: ";
    std::cin >> amount;

    fibSequence(amount);

    return 0;
}
