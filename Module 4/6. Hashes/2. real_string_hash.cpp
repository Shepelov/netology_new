#include <iostream>
#include <Windows.h>
#include <cmath>

int real_string_hash(std::string str, int p, int n) {
    long long sum{};
    for (int i = 0; i < str.size(); ++i) {
        sum += str[i] * pow(p, i);
    }
    int hash = sum % n;
    return hash;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    std::string string;
    int p;
    int n;

    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    do {
        std::cout << "Введите строку: ";
        std::cin >> string;
        std::cout << "Хэш строки " << string << " = " << real_string_hash(string, p, n) << std::endl;
    } while (string != "exit");
}
