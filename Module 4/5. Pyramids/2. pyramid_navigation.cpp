#include <iostream>
#include <Windows.h>

void print_array(int* arr, int arr_size) {
    for (int i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_element(int* arr, int ptr) {
    std::cout << round(sqrt(ptr)) << " ";
    if (ptr == 0) {
        std::cout << "root";
    }
    else if (ptr % 2 == 0) {
        std::cout << "right";
    }
    else {
        std::cout << "left";
    }
    if (ptr != 0) {
        std::cout << "(" << arr[(ptr - 1) / 2] << ")";
    }
    std::cout << " " << arr[ptr];

    std::cout << std::endl;
}

void print_pyramid(int* arr, int arr_size) {
    for (int i = 0; i < arr_size; ++i) {
        print_element(arr, i);
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int arr[] = { 1, 3, 6, 5, 9, 8 };
    //int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    //int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arr_size = 6;
    //int arr_size = 8;
    //int arr_size = 10;
    std::string command;
    int ptr = 0;

    std::cout << "Исходный массив: ";
    print_array(arr, arr_size);
    std::cout << "Пирамида: " << std::endl;
    print_pyramid(arr, arr_size);
    do {
        std::cout << "Вы находитесь здесь: ";
        print_element(arr, ptr);
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "left") {
            int newptr = 2 * ptr + 1;
            if (newptr > arr_size-1) {
                std::cout << "Ошибка! Отсутствует левый потомок!" << std::endl;
            }
            else {
                std::cout << "OK" << std::endl;
                ptr = newptr;
            }
        }
        else if (command == "right") {
            int newptr = 2 * ptr + 2;
            if (newptr > arr_size-1) {
                std::cout << "Ошибка! Отсутствует правый потомок!" << std::endl;
            }
            else {
                std::cout << "OK" << std::endl;
                ptr = newptr;
            }
        }
        else if (command == "up") {
            if (ptr == 0) {
                std::cout << "Ошибка! Отсутствует родитель!" << std::endl;
            }
            else {
                std::cout << "OK" << std::endl;
                ptr = (ptr - 1) / 2;
            }

        }
        else if (command == "exit") {

        }
        else {
            std::cout << "Введена неизвестная команда!" << std::endl;
        }
    } while (command != "exit");
    std::cout << "Завершение работы программы! До свидания!";
}
