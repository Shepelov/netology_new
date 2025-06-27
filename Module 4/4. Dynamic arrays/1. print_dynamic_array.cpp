#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int size_fact;
    int size_logic;
    int* dynamic_array;

    std::cout << "Введите фактический размер массива: ";
    std::cin >> size_fact;
    std::cout << "Введите логический размер массива: ";
    std::cin >> size_logic;

    if (size_logic > size_fact) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        exit(1);
    }
    else {
        dynamic_array = new int[size_fact];
    }

    for (int i = 0; i < size_fact; ++i) {
        if (i < size_logic) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> dynamic_array[i];
        }
        
    }

    print_dynamic_array(dynamic_array, size_logic, size_fact);
}
