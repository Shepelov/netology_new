#include <iostream>
#include <windows.h>
#include <clocale>

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int arraySize;

    std::cout << "Введите размер массива: ";
    std::cin >> arraySize;
    int* array {new int[arraySize]};
    for (int element{}; element < arraySize; ++element){
        std::cout << "arr[" << element << "] = ";
        std::cin >> array[element];
    }
    std::cout << "Введенный массив: ";
    for (int element{}; element < arraySize; ++element){
        std::cout << array[element] << " ";
    }
    delete[] array;

    return 0;
}
