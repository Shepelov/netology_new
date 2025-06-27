#include <iostream>
#include <Windows.h>

int binarySearch(int array[], int arrayLength, int value) {
    int leftValue{ 0 };
    int rightValue{ arrayLength - 1 };
    bool searchDone{ false };
    int index;

    //проверка выхода переданного значения за границы исходного массива
    //если true - нет смысла запускать бинарный поиск
    if (value < array[0]) {
        return arrayLength;
    }
    else if (value >= array[arrayLength - 1]) {
        return 0;
    }

    do {
        index = leftValue + (rightValue - leftValue) / 2;
        if (array[index] < value) {
            leftValue = index;
        }
        else if (array[index] > value) {
            rightValue = index;
        }

        if (array[index] == value || rightValue - leftValue < 2) {
            searchDone = true;
        }
    } while (!searchDone);

    return arrayLength - index - 1;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    //входные данные
    int value;
    int array[]{ 14, 16, 19, 32, 35, 42, 56, 69, 72 };
    int arrayLength{ 9 };


    std::cout << "Введите точку отсчета: ";
    std::cin >> value;

    std::cout << "Количество элементов в массиве, больших чем " << value << ": " << binarySearch(array, arrayLength, value) << std::endl;
}
