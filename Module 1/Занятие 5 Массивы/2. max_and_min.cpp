#include <iostream>
#include <windows.h>
#include <clocale>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int array[] {14, 28, 13, 8, -102, 458, -89, -8, 45, 62};
    int array_size = sizeof (array) / sizeof (array[0]);
    int min {array[0]}, max{array[0]};

    std::wcout << L"Массив: ";
    for (int i{}; i<array_size; ++i){
        std::cout << array[i];
	if(min > array[i]) min = array[i];
        if(max < array[i]) max = array[i];
        if (i == array_size-1){
            std::cout << std::endl;
            continue;
        }
        std::cout << ", ";
    }

    std::wcout << L"Минимальное значение: " << min << std::endl <<  L"Максимальное значение: " << max << std::endl;

    return 0;
}
