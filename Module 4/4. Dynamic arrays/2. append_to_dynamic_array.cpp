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

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int append) {
    if (append == 0) {      //0 - стоп-символ. его в массив не добавляем
        return arr;
    }
    if (logical_size < actual_size) {
        arr[logical_size] = append;
        logical_size++;
        return arr;
    }
    else if (logical_size == actual_size) {
        int* new_arr = new int[actual_size * 2];
        for (int i = 0; i < actual_size; ++i){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        new_arr[logical_size] = append;
        logical_size++;
        actual_size *= 2;
        return new_arr;
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int size_fact;
    int size_logic;
    int* dynamic_array;
    int append;

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
            std::cout << "Введите элемент для добавления: ";
            std::cin >> append;
            dynamic_array = append_to_dynamic_array(dynamic_array, size_logic, size_fact, append);
    } while (append != 0);

    std::cout << "Спасибо! Ваш массив заполнен!" << std::endl;
    print_dynamic_array(dynamic_array, size_logic, size_fact);
}
