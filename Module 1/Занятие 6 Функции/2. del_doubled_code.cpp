#include <iostream>
#include <clocale>
#include <windows.h>



void printPowerOfInt (int value, int power){
    int result{1};
    for (int i{}; i < power; ++i){
        result *= value;
    }
    std::wcout << value << L" в степни " << power << " = " << result << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printPowerOfInt (5, 2);
    printPowerOfInt (3, 3);
    printPowerOfInt (4, 4);

    return 0;
}
