#include <iostream>
#include <windows.h>
#include <clocale>
//#include <string>

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    std::wstring word = L"программист";
    std::wstring answer;

    do{
        std::wcout << L"Угадайте профессию: ";
        std::getline(std::wcin, answer);
        if(word != answer){
            std::wcout << L"Неправильно!" << std::endl;
        }
        else{
            std::wcout << L"Правильно! Вы победили! Загаданная профессия - " << word << std::endl;
        }
    }
    while(word != answer);

    return 0;
}
