#include <iostream>
#include <Windows.h>

int simple_string_hash(std::string str) {
    int hash{};
    for (int i = 0; i < str.size(); ++i) {
        hash += str[i];
    }
    return hash;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    std::string string;

    do {
        std::cout << "Введите строку: ";
        std::cin >> string;
        std::cout << "Наивный хэш строки " << string << " = " << simple_string_hash(string) << std::endl;
    } while (string != "exit");
}
