#include <iostream>
#include <windows.h>
#include <clocale>

void counting_function();

int main(int argc, char** argv)
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
}

void counting_function(){
    static int counter;
    std::wcout << L"Количество вызовов функции counting_function(): " << ++counter << std::endl;
}
