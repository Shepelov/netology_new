#include <iostream>
#include <windows.h>
#include <clocale>

void reverse (int* mass, int massSize);
void print (int* mass, int massSize);

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    int mass[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    constexpr int massSize = sizeof (mass) / sizeof (int);
    std::wcout << L"Массив до изменения: ";
    print (mass, massSize);
    reverse (mass, massSize);
    std::wcout << L"Массив после изменения: ";
    print (mass, massSize);
}

void reverse (int* mass, int massSize){
    int tempMass[massSize];
    for (int element{}; element < massSize; ++element){
        tempMass[element] = mass[element];
    }
    for (int element{}; element < massSize; ++element){
        mass[element] = tempMass[massSize - element - 1];
    }
}

void print (int* mass, int massSize){
    for (int element{}; element < massSize; ++element){
        std::cout << mass[element] << " ";
    }
    std::cout << std::endl;
}
