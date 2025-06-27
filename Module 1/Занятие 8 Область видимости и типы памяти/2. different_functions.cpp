#include <iostream>
#include <windows.h>
#include <clocale>

namespace Summ {
    int calc (int x, int y);
}

namespace Diff {
    int calc (int x, int y);
}

namespace Mult {
    int calc (int x, int y);
}

namespace Div {
    int calc (int x, int y);
}

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int x{};
    int y{};

    std::wcout << L"Введите число 1: ";
    std::cin >> x;
    std::wcout << L"Введите число 2: ";
    std::cin >> y;
    std::cout << std::endl << "x = " << x << ", y = " << y << std::endl;
    std::wcout << L"Сложение: " << Summ::calc(x, y) << std::endl;
    std::wcout << L"Вычитание: " << Diff::calc(x, y) << std::endl;
    std::wcout << L"Умножение: " << Mult::calc(x, y) << std::endl;
    std::wcout << L"Деление: " << Div::calc(x, y) << std::endl;
}

int Summ::calc(int x, int y){
    return x + y;
}

int Diff::calc(int x, int y){
    return x - y;
}

int Mult::calc(int x, int y){
    return x * y;
}

int Div::calc(int x, int y){
    return x / y;
}
