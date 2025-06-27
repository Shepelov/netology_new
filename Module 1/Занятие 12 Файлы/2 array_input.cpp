#include <iostream>
#include <fstream>
#include <windows.h>
#include <clocale>

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    std::ifstream file {"in.txt"};
    int arraySize{};
    int* array;
    if(file.is_open()){
        file >> arraySize;
        array = new int[arraySize];
        for (int i{}; i < arraySize; ++i){
                file >> array[i];
        }
	file.close();
	delete[] array;
    }
    else{
        std::wcout << L"Ошибка открытия файла!" << std::endl;
    }

    for (int i{}; i < arraySize; ++i){
        std::cout << array[arraySize - i - 1] << " ";
    }

    return 0;
}
