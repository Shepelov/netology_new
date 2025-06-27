#include <iostream>
#include <windows.h>
#include <clocale>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int array[3][6] {
        {5, 78, 34, 13, 67, 98},
        {34, -78, 8, -89, 56, -7},
        {8, 3, -13, 4, 56, 52}
    };

    int min{array[0][0]}, max{array[0][0]}, min_index_i{}, min_index_j{}, max_index_i{}, max_index_j{};

    std::wcout << L"Массив:" << std::endl;

    for (int i{}; i<3; ++i){
        for (int j{}; j<6; ++j){
            std::cout << array[i][j] << "\t";
            if(min > array[i][j]){
                min = array[i][j];
                min_index_i = i;
                min_index_j = j;
            };
            if(max < array[i][j]){
                max = array[i][j];
                max_index_i = i;
                max_index_j = j;
            };
        }
        std::cout << std::endl;
    }

    std::wcout << L"Индекс минимального элемента: " << min_index_i << " " << min_index_j << std::endl;
    std::wcout << L"Индекс максимального элемента: " << max_index_i << " " << max_index_j << std::endl;

    return 0;
}
