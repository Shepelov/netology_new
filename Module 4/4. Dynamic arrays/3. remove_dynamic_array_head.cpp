#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
    if (logical_size == 0) {
        std::cout << "Невозможно произвести удаление, так как динамический массив пуст!" << std::endl;
        return arr;
    }
    int new_arr_size = actual_size / 3;
    if (new_arr_size == 0) { new_arr_size = 1; }
    if (logical_size - 1 > new_arr_size) {
        for (int i = 0; i < logical_size; ++i) {
            arr[i] = arr[i + 1];
        }
        logical_size--;
        return arr;
    }
    else {
        int* new_arr = new int[new_arr_size];
        for (int i = 0; i < new_arr_size; ++i) {
            new_arr[i] = arr[i + 1];
        }
        delete[] arr;
        logical_size--;
        actual_size = new_arr_size;
        return new_arr;
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int size_fact;
    int size_logic;
    int* dynamic_array;
    int answer;

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

   do{
            print_dynamic_array(dynamic_array, size_logic, size_fact);
            std::cout << "Удалить первый элемент массива? (1 - да, 2 - нет): ";
            std::cin >> answer;
            if (answer == 1) {
                dynamic_array = remove_dynamic_array_head(dynamic_array, size_logic, size_fact);
            }
    } while (answer != 2);

    std::cout << "Спасибо!" << std::endl;
    print_dynamic_array(dynamic_array, size_logic, size_fact);
}
