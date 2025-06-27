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

int* deep_pass(int** matrix, int matrix_size) {
    int* visited_nodes = new int[matrix_size];
    int visited_counter { 1 };
    bool* visited = new bool[matrix_size];
    std::vector<int> pass_way;
    int start_node = 0;
    int node = start_node;
    pass_way.push_back(node);
    visited_nodes[0] = start_node + 1;
    bool check { false };
    bool is_pass_end;
    for (int i = 0; i < matrix_size; ++i) {
        visited[i] = false;
    }
    do {
        do {
            visited[node] = true;
            check = false;
            for (int i = 0; i < matrix_size; ++i) {
                if (matrix[node][i] == 1 && check == false && visited[i] == false) {
                    check = true;
                    node = i;
                    visited[i] = true;
                    visited_nodes[visited_counter] = i + 1;
                    visited_counter++;
                    pass_way.push_back(i);
                }
            }
            if (check == false) {
                pass_way.pop_back();
                if (pass_way.size() != 0) {
                    node = pass_way[pass_way.size() - 1];
                }
            }
        } while (pass_way.size() > 0);

        is_pass_end = true;
        for (int i = 0; i < matrix_size; ++i) { //обход массива посещенных элементов в поиске непосещенных
            if (visited[i] == false) {
                is_pass_end = false;
                node = i;
            }
        }
    } while (!is_pass_end);
    
    delete[] visited;

    return visited_nodes;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int matrix_size;
    int** matrix = read_matrix(matrix_size);
    int* visited = deep_pass(matrix, matrix_size);

    std::cout << "Порядок обхода вершин: ";
    for (int i = 0; i < matrix_size; ++i) {
        std::cout << visited[i] << " ";
    }
    std::cout << std::endl;

    //удаление динамических массивов
    for (int i = 0; i < matrix_size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;
}