#include <iostream>
#include <Windows.h>

void merge_sort(int* arr, int size) {
    if (size > 1) {
        int mid = size / 2;
        int* left = new int[mid];
        int* right = new int[size - mid];
        for (int i = 0; i < size; ++i) {
            if (i < mid) {
                left[i] = arr[i];
            }
            else {
                right[i - mid] = arr[i];
            }
        }

        merge_sort(left, mid);
        merge_sort(right, size - mid);

        int leftCntr = 0;
        int rightCntr = 0;
        int resultCntr = 0;
        while (leftCntr < mid || rightCntr < size - mid) {
            if (leftCntr < mid && rightCntr < size - mid) {
                if (left[leftCntr] <= right[rightCntr]) {
                    arr[resultCntr] = left[leftCntr];
                    leftCntr++;
                }
                else {
                    arr[resultCntr] = right[rightCntr];
                    rightCntr++;
                }
                resultCntr++;
            }
            else if (leftCntr == mid) {
                arr[resultCntr] = right[rightCntr];
                rightCntr++;
                resultCntr++;
            }
            else if (rightCntr == size - mid) {
                arr[resultCntr] = left[leftCntr];
                leftCntr++;
                resultCntr++;
            }
        }
        delete[] left;
        delete[] right;
    }
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = 10;
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = 15;
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = 18;
    
    std::cout << "Тестирование сортировки слиянием" << std::endl;
    std::cout << "--------------------------------" << std::endl << std::endl;

    std::cout << "Массив 1 до сортировки: ";
    print_arr(arr1, size1);
    merge_sort(arr1, size1);
    std::cout << "Массив 1 после сортировки: ";
    print_arr(arr1, size1);

    std::cout << std::endl;

    std::cout << "Массив 2 до сортировки: ";
    print_arr(arr2, size2);
    merge_sort(arr2, size2);
    std::cout << "Массив 2 после сортировки: ";
    print_arr(arr2, size2);

    std::cout << std::endl;

    std::cout << "Массив 3 до сортировки: ";
    print_arr(arr3, size3);
    merge_sort(arr3, size3);
    std::cout << "Массив 3 после сортировки: ";
    print_arr(arr3, size3);
}
