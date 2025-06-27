#include <iostream>
#include <Windows.h>

void print_pyramid(int* arr, int arr_size) {
    for (int i = 0; i < arr_size; ++i) {
        std::cout << round(sqrt(i)) << " ";
        if (i == 0) {
            std::cout << "root";
        }
        else if (i % 2 == 0) {
            std::cout << "right";
        }
        else {
            std::cout << "left";
        }
        if (i != 0) {
            std::cout << "(" << arr[(i - 1) / 2] << ")";
        }
        std::cout << " " << arr[i];

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int arr1_size = 6;
    int arr2_size = 8;
    int arr3_size = 10;

    print_pyramid(arr1, arr1_size);
    print_pyramid(arr2, arr2_size);
    print_pyramid(arr3, arr3_size);
}
