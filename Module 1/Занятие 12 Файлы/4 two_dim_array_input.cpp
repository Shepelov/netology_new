#include <iostream>
#include <fstream>
#include <windows.h>
#include <clocale>

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    std::ifstream file {"in.txt"};
    if(file.is_open()){
        int rows;
        int columns;
        file >> rows;
        file >> columns;
        int** array = new int*[rows];
        for (int i{}; i < rows; ++i){
            array[i] = new int[columns];
        }

        for (int i{}; i < rows; ++i){
            for (int j{}; j < columns; ++j){
                file >> array[i][j];
            }
        }
        file.close();

        for (int i{}; i < rows; ++i){
            for (int j{columns - 1}; j >=0; --j){
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }

        for (int i{}; i < rows; ++i){
            delete[] array[i];
        }
        delete[] array;
    }
    else{
        std::wcout << L"Ошибка при открытии файла!";
    }


    return 0;
}
