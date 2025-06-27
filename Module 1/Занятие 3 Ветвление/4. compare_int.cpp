#include <iostream>
#include <string>
#include <windows.h>
#include <clocale>

std::wstring intToString (int value) {  //функция перевода числа в текстовый формат
    //находим модуль числа
    int module = abs(value);

    //проверка на отрицательное число
    std::wstring negative = value < 0 ? L"минус " : L"";

    //объявляем переменные для первого и второго слова в названии числа
    std::wstring name1{L"ноль"};
    std::wstring name2{L""};

    //составляем текстовые имена для чисел
    //для чисел -100, 100
    if (module == 100) {
        name1 = L"cто";
    }

    //для чисел от -99 до -20, от -9 до -1, от 1 до 9, от 20 до 99
    else if ((module > 0 && module < 10) || (module > 19 && module < 100)) {
        int order1 = module%10; //1-й разряд числа
        int order2 = module/10; //2-й разряд числа
        switch (order1) {
            case 0: name2 = L""; break;
            case 1: name2 = L"один"; break;
            case 2: name2 = L"два"; break;
            case 3: name2 = L"три"; break;
            case 4: name2 = L"четыре"; break;
            case 5: name2 = L"пять"; break;
            case 6: name2 = L"шесть"; break;
            case 7: name2 = L"семь"; break;
            case 8: name2 = L"восемь"; break;
            case 9: name2 = L"девять"; break;
        }
        switch (order2) {
            case 0: name1 = L""; break;
            case 2: name1 = L"двадцать "; break;
            case 3: name1 = L"тридцать "; break;
            case 4: name1 = L"сорок "; break;
            case 5: name1 = L"пятьдесят "; break;
            case 6: name1 = L"шестьдесят "; break;
            case 7: name1 = L"семьдесят "; break;
            case 8: name1 = L"восемьдесят "; break;
            case 9: name1 = L"девяносто "; break;
        }
    }

    //для чисел от -19 до -10, от 10 до 19
    else if (module > 9 && module < 20) {
        switch (module) {
            case 10: name1 = L"десять"; break;
            case 11: name1 = L"одиннадцать"; break;
            case 12: name1 = L"двенадцать"; break;
            case 13: name1 = L"тринадцать"; break;
            case 14: name1 = L"четырнадцать"; break;
            case 15: name1 = L"пятнадцать"; break;
            case 16: name1 = L"шестнадцать"; break;
            case 17: name1 = L"семнадцать"; break;
            case 18: name1 = L"восемнадцать"; break;
            case 19: name1 = L"девятнадцать"; break;
        }
    }

    return negative + name1 + name2;
}

int main()
{
    //локализация
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    //ввод-вывод
    int integer1, integer2;
    std::wcout << L"Введите целое число: ";
    std::cin >> integer1;
    std::wcout << L"Введите целое число: ";
    std::cin >> integer2;

    //проверка на ошибку диапазона
    if (abs(integer1) > 100 || abs(integer2) > 100){
        std::wcout << L"Ошибка! Одно из чисел вне диапазона!";
    }
    else{
        //если ошибки нет - отрабатываем логику программы и выводим данные
        std::wcout << intToString(integer1) << (integer1 < integer2 ? L" меньше чем " : (integer1 > integer2 ? L" больше чем " : L" равно ")) << intToString(integer2);
    }

    return 0;
}
