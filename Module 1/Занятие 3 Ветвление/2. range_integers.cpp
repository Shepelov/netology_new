#include <iostream>

int main()
{
    //объявление переменных
    int value1, value2, value3, min, mid, max;

    //ввод-вывод
    std::cout << "Enter the value 1: ";
    std::cin >> value1;
    std::cout << "Enter the value 2: ";
    std::cin >> value2;
    std::cout << "Enter the value 3: ";
    std::cin >> value3;

    //логика программы
    min = value1 < value2 ? (value1 < value3 ? value1 : value3) : (value2 < value3 ? value2 : value3);
    mid = value1 < value2 ? (value1 > value3 ? value1 : value3) : (value2 > value3 ? value2 : value3);
    max = value1 > value2 ? (value1 > value3 ? value1 : value3) : (value2 > value3 ? value2 : value3);

    //вывод результата
    std::cout << min << "\t" << mid << "\t" << max;
    return 0;
}
