#include <iostream>
#include <fstream>
#include <windows.h>
#include <clocale>

int main(int argc, char** argv){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    std::ifstream file {"in.txt"};
    std::string data;
    if(file.is_open()){
        while (file >> data){
            std::cout << data << std::endl;
        }
	file.close();
    }
    else{
        std::wcout << L"Ошибка открытия файла!" << std::endl;
    }

    return 0;
}
