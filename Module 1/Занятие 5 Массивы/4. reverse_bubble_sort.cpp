#include <iostream>
#include <windows.h>
#include <clocale>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int array[] {5, 78, 34, 13, 67, 98, 34, -78, 8, -89};
    int array_size = sizeof (array) / sizeof (array[0]);
    bool swap{false};

    std::wcout << L"Массив до сортировки: ";

    for (int i{}; i<array_size; ++i){
            std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    do{
        swap = false;
        for (int i{array_size-1}; i>0; --i){
            if (array[i] < array[i-1]){
                int temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swap = true;
            }
        }
    }
    while(swap == true);

    std::wcout << L"Массив после сортировки: ";

    for (int i{}; i<array_size; ++i){
            std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
