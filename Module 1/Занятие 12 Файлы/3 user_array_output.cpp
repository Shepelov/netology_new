#include <iostream>
#include <fstream>
#include <windows.h>
#include <clocale>

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    std::wcout << L"Введите размер массива: ";
    int arraySize;
    std::cin >> arraySize;
    int* array = new int[arraySize];
    for (int i{}; i < arraySize; ++i){
        std::cout << "arr[" << i << "]: ";
        std::cin >> array[i];
    }

    std::ofstream file {"out.txt"};
    if (file.is_open()){
        file << arraySize << "\n";
        for (int i{}; i < arraySize; ++i){
            file << array[arraySize - i - 1] << " ";
        }
        file.close();
        std::wcout << L"Данные успешно записаны в файл!";
    }
    else{
        std::wcout <<L"Ошибка при открытии файла!";
    }

    delete[] array;
    return 0;
}
