#include <windows.h>
#include <clocale>
#include <iostream>
#include <string>

int main()
{
    //локализация
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    //объявляем переменные
    std::wstring sex, zodiac;
    int age;

    //ввод-вывод
    std::wcout << L"Введите пол: ";
    std::wcin >> sex;
    std::wcout << L"Введите знак зодиака: ";
    std::wcin >> zodiac;
    std::wcout << L"Введите возраст: ";
    std::cin >> age;
    std::wcout << L"Ваше предсказание: " << std::endl;

    //логика программы + вывод результатов
    if (sex == L"м" && (zodiac == L"рак" || zodiac == L"скорпион" || zodiac == L"рыбы") && age < 40) {
        std::wcout << L"Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным.";
    }
    else if (sex == L"ж" && (zodiac == L"телец" || zodiac == L"дева" || zodiac == L"козерог") && age >= 15 && age <= 30) {
        std::wcout << L"Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок."
                      << std::endl << L"Будет не только весело, но и интересно: найдётся дело, которое увлечёт всех.";
    }
    else {
        std::wcout << L"Гороскоп для вас находится в разработке. Приходите чуточку позже ;)";
    }

    return 0;
}
