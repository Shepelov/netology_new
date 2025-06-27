#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

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

int* topology_sort(int** matrix, int matrix_size) {
    int* topology = new int[matrix_size];
    int topology_counter{ 0 };
    bool* visited = new bool[matrix_size];
    bool is_pass_end;

    for (int i = 0; i < matrix_size; ++i) {
        visited[i] = false;
    }

    do {
        for (int i = 0; i < matrix_size; ++i) { //находим узел без входящих дуг
            if (!visited[i]) {
                bool check{ true };
                for (int j = 0; j < matrix_size; ++j) {
                    if (matrix[j][i] == 1 && visited[j] == false) { //не беря во внимание входящие дуги с уже посещенных вершин
                        check = false;
                    }
                }
                if (check) {
                    topology[topology_counter] = i + 1;
                    topology_counter++;
                    visited[i] = true;
                    break;
                }
            }
        }

        is_pass_end = true;
        for (int i = 0; i < matrix_size; ++i) {
            if (!visited[i]) {
                is_pass_end = false;
            }
        }
    } while (!is_pass_end);

    delete[] visited;

    return topology;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int matrix_size;

    int** matrix = read_matrix(matrix_size);
    int* topology = topology_sort(matrix, matrix_size);

    for (int i = 0; i < matrix_size; ++i) {
        std::cout << topology[i] << " ";
    }
    std::cout << std::endl;

    //удаление динамических массивов
    for (int i = 0; i < matrix_size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] topology;
}