#include <iostream>
#include <windows.h>
#include <clocale>

double* create_array(int arraySize);

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int* arraySize{new int};
    std::wcout << L"Введите размер массива: ";
    std::wcin >> *arraySize;
    double* array {create_array(*arraySize)};
    std::wcout << L"Массив: ";
    for(int element{}; element < *arraySize; ++element){
        std::wcout << array[element] << " ";
    }
    delete arraySize;
    delete[] array;

    return 0;
}

double* create_array(int arraySize){
    double* array {new double[arraySize]};
    for(int element{}; element < arraySize; ++element){
        array[element] = 0.0;
    }
    return array;
}
