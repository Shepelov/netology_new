#include <iostream>
#include <windows.h>
#include <clocale>

int** create_two_dim_array(int rows, int columns);
void fill_two_dim_array(int** array, int rows, int columns);
void print_two_dim_array(int** array, int rows, int columns);
void delete_two_dim_array(int** array, int rows, int columns);

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int rows;
    int columns;

    std::cout << "Введите количество cтолбцов: ";
    std::cin >> columns;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Таблица умножения: " << std::endl;
    int** multiplicationSheet = create_two_dim_array(rows, columns);
    fill_two_dim_array(multiplicationSheet, rows, columns);
    print_two_dim_array(multiplicationSheet, rows, columns);
    delete_two_dim_array(multiplicationSheet, rows, columns);

    return 0;
}

int** create_two_dim_array(int rows, int columns){
    int** array = new int*[rows];
    for(int element{}; element < rows; ++element){
        array[element] = new int[columns];
    }
    return array;
}

void fill_two_dim_array(int** array, int rows, int columns){
    for(int row{}; row < rows; ++row){
        for(int element{}; element < columns; ++element){
            array[row][element] = (row + 1) * (element + 1);
        }
    }
}

void print_two_dim_array(int** array, int rows, int columns){
    for(int row{}; row < rows; ++row){
        for(int element{}; element < columns; ++element){
            std::cout << array[row][element] << "\t";
        }
        std::cout << std::endl;
    }
}

void delete_two_dim_array(int** array, int rows, int columns){
    for(int row{}; row < rows; ++row){
        delete[] array[row];
    }
    delete[] array;
}
