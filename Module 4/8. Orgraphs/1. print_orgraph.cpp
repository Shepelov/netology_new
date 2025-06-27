#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

int** read_matrix(int& matrix_size) {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        exit(1);
    }
    std::string read;
    file >> read;
    matrix_size = std::stoi(read);
    int** matrix = new int* [matrix_size];
    for (int i = 0; i < matrix_size; ++i) {
        matrix[i] = new int[matrix_size];
    }
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            file >> read;
            matrix[i][j] = std::stoi(read);
        }
    }

    return matrix;
}

void print_orgraph(int** matrix, int matrix_size) {
    for (int i = 0; i < matrix_size; ++i) {
        std::cout << i+1 << ": ";
        bool check{ false };
        for (int j = 0; j < matrix_size; ++j) {
            if (matrix[i][j] == 1) {
                std::cout << j + 1 << " ";
                check = true;
            }
        }
        if (!check) {
            std::cout << "нет";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int matrix_size;

    int** matrix = read_matrix(matrix_size);
    print_orgraph(matrix, matrix_size);


    //удаление динамических массивов
    for (int i = 0; i < matrix_size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}