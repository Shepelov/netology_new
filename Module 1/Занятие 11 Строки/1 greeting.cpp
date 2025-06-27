#include <iostream>
#include <windows.h>
#include <clocale>

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    std::wstring name;
    std::wstring surname;

    std::wcout << L"Введите имя: ";
    std::wcin >> name;
    std::wcout << L"Введите фамилию: ";
    std::wcin >> surname;
    std::wcout << L"Здравствуйте, " << name + L" " + surname + L"!";

    return 0;
}
