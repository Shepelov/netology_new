#include <iostream>
#include <Windows.h>
#include <cmath>

int hash(std::string str, int p, int n) {
    long long sum{};
    for (int i = 0; i < str.size(); ++i) {
        sum += str[i] * pow(p, i);
    }
    int hash = sum % n;
    return hash;
}

int find_substring_light_rabin_karp(std::string str, std::string substr) {
    int substr_hash = hash(substr, 29, 1000);
    for (int i = 0; i < str.size() - substr.size() + 1; ++i) {
        std::string sample {substr};
        for (int j = 0; j < substr.size(); ++j) {
            sample[j] = str[j + i];
        }
        int sample_hash = hash(sample, 29, 1000);
        if (sample_hash == substr_hash) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");

    std::string string;
    std::string substring;

    std::cout << "Введите строку: ";
    std::cin >> string;

    do {
        std::cout << "Введите подстроку: ";
        std::cin >> substring;
        if (find_substring_light_rabin_karp(string, substring) == -1) {
            std::cout << "Подстрока " << substring << " не найдена!" << std::endl;
        }
        else {
            std::cout << "Подстрока " << substring << " найдена по адресу " << find_substring_light_rabin_karp(string, substring) << std::endl;
        }
    } while (substring != "exit");
}
