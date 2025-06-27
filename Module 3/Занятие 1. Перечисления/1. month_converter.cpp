#include <iostream>
#include <Windows.h>
#include <clocale>

enum class Months {
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

int number;
Months month;
std::string month_name;

int main(){
    setlocale(LC_ALL, "rus");

    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> number;
        if (number == 0) {
            std::cout << "До свидания!" << std::endl;
            continue;
        }
        else {
            month = static_cast<Months>(number);
            switch (month) {
            case Months::jan:
                month_name = "Январь";
                break;
            case Months::feb:
                month_name = "Февраль";
                break;
            case Months::mar:
                month_name = "Март";
                break;
            case Months::apr:
                month_name = "Апрель";
                break;
            case Months::may:
                month_name = "Май";
                break;
            case Months::jun:
                month_name = "Июнь";
                break;
            case Months::jul:
                month_name = "Июль";
                break;
            case Months::aug:
                month_name = "Август";
                break;
            case Months::sep:
                month_name = "Сентябрь";
                break;
            case Months::oct:
                month_name = "Октябрь";
                break;
            case Months::nov:
                month_name = "Ноябрь";
                break;
            case Months::dec:
                month_name = "Декабрь";
                break;
            default:
                std::cout << "Вы ввели некорректное значение!" << std::endl;
                continue;
            }
            std::cout << month_name << std::endl;
        }
    } while (number != 0);
}
