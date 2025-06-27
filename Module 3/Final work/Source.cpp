#include "vehicles/Camel.h"
#include "vehicles/FastCamel.h"
#include "vehicles/Centaur.h"
#include "vehicles/AllTerrainBoots.h"
#include "vehicles/MagicCarpet.h"
#include "vehicles/Eagle.h"
#include "vehicles/Broom.h"

#include <iostream>
#include <Windows.h>
#include <vector>

struct Result {
    std::string name;
    double time;
};

void race();
std::vector<Result> sortResults(std::vector<Result>);

int main(int argc, char* argv)
{
    setlocale(LC_ALL, "Rus");

    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    int select;
    do {
        race();
        do {
            std::cout << std::endl;
            std::cout << "Желаете провести еще одну гонку?" << std::endl;
            std::cout << "1 - Да, 2 - Нет" << std::endl;
            std::cout << "Ваш выбор: ";
            std::cin >> select;
            if (select == 2) {
                std::cout << "Работа симулятора завершена! До свидания!" << std::endl;
            }
            if (select != 1 && select != 2) {
                std::cout << "Введено неверное значение!" << std::endl;
            }
        } while (select != 1 && select != 2);
    } while (select == 1);
    
}

void race() {
    int raceType;
    int distance;
    std::vector<Result> results;
    int select;

    std::cout << "1. Гонка для наземного транспорта" << std::endl;
    std::cout << "2. Гонка для воздушного транспорта" << std::endl;
    std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
    do {
        std::cout << "Выберите тип гонки: ";
        std::cin >> raceType;
        if (raceType < 1 || raceType > 3) {
            std::cout << "Вы ввели неверное значение!" << std::endl;
        }
    } while (raceType < 1 || raceType > 3);
    std::cout << "Укажите длину дистанции (должна быть положительным целым числом): ";
    std::cin >> distance;
    std::cout << std::endl;

    Camel* camel = new Camel(distance);
    FastCamel* fastCamel = new FastCamel(distance);
    Centaur* centaur = new Centaur(distance);
    AllTerrainBoots* allTerrainBoots = new AllTerrainBoots(distance);
    MagicCarpet* magicCarpet = new MagicCarpet(distance);
    Eagle* eagle = new Eagle(distance);
    Broom* broom = new Broom(distance);

    do {
        if (results.size() < 2) {
            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
        }
        std::cout << "1. Зарегистрировать транспорт" << std::endl;
        if (results.size() >= 2) {
            std::cout << "2. Начать гонку" << std::endl;
        }
        std::cout << "Выберите действие: ";
        std::cin >> select;
        std::cout << std::endl;
        if (select == 1) {
            do {
                std::cout << "Гонка для ";
                switch (raceType) {
                case 1:
                    std::cout << "наземного";
                    break;
                case 2:
                    std::cout << "воздушного";
                    break;
                case 3:
                    std::cout << "наземного и воздушного";
                    break;
                }
                std::cout << " транспорта. Расстояние: " << distance << std::endl;
                if (results.size() != 0) {
                    std::cout << "Зарегистрированные транспортные средства: ";
                    for (int i = 0; i < results.size(); ++i) {
                        if (i > 0) {
                            std::cout << ", ";
                        }
                        std::cout << results[i].name;
                    }
                    std::cout << std::endl;
                }
                std::cout << "1. " << allTerrainBoots->getName() << std::endl;
                std::cout << "2. " << broom->getName() << std::endl;
                std::cout << "3. " << camel->getName() << std::endl;
                std::cout << "4. " << centaur->getName() << std::endl;
                std::cout << "5. " << eagle->getName() << std::endl;
                std::cout << "6. " << fastCamel->getName() << std::endl;
                std::cout << "7. " << magicCarpet->getName() << std::endl;
                std::cout << "0. Закончить регистрацию" << std::endl;
                std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
                std::cin >> select;
                std::cout << std::endl;
                switch (select) {
                case 1:
                    if (allTerrainBoots->regist() && raceType != 2) {
                        results.push_back(Result{ allTerrainBoots->getName(), allTerrainBoots->getRaceTime()});
                    }
                    else if (raceType == 2) {
                        std::cout << "Нельзя зарегистрировать " << allTerrainBoots->getName() << " на гонку для воздушного транспорта!" << std::endl;
                    }
                    else {
                        std::cout << allTerrainBoots->getName() << " уже зарегистрирован!" << std::endl;
                    }
                    break;
                case 2:
                    if (broom->regist() && raceType != 1) {
                        results.push_back(Result{ broom->getName(), broom->getRaceTime() });
                    }
                    else if (raceType == 1) {
                        std::cout << "Нельзя зарегистрировать " << broom->getName() << " на гонку для наземного транспорта!" << std::endl;
                    }
                    else {
                        std::cout << broom->getName() << " уже зарегистрирован!" << std::endl;
                    }
                    break;
                case 3:
                    if (camel->regist() && raceType != 2) {
                        results.push_back(Result{ camel->getName(), camel->getRaceTime() });
                    }
                    else if (raceType == 2) {
                        std::cout << "Нельзя зарегистрировать " << camel->getName() << " на гонку для воздушного транспорта!" << std::endl;
                    }
                    else {
                        std::cout << camel->getName() << " уже зарегистрирован!" << std::endl;
                    }
                    break;
                case 4:
                    if (centaur->regist() && raceType != 2) {
                        results.push_back(Result{ centaur->getName(), centaur->getRaceTime() });
                    }
                    else if (raceType == 2) {
                        std::cout << "Нельзя зарегистрировать " << centaur->getName() << " на гонку для воздушного транспорта!" << std::endl;
                    }
                    else {
                        std::cout << centaur->getName() << " уже зарегистрирован!" << std::endl;
                    }
                    break;
                case 5:
                    if (eagle->regist() && raceType != 1) {
                        results.push_back(Result{ eagle->getName(), eagle->getRaceTime() });
                    }
                    else if (raceType == 1) {
                        std::cout << "Нельзя зарегистрировать " << eagle->getName() << " на гонку для наземного транспорта!" << std::endl;
                    }
                    else {
                        std::cout << eagle->getName() << " уже зарегистрирован!" << std::endl;
                    }
                    break;
                case 6:
                    if (fastCamel->regist() && raceType != 2) {
                        results.push_back(Result{ fastCamel->getName(), fastCamel->getRaceTime() });
                    }
                    else if (raceType == 2) {
                        std::cout << "Нельзя зарегистрировать " << fastCamel->getName() << " на гонку для воздушного транспорта!" << std::endl;
                    }
                    else {
                        std::cout << fastCamel->getName() << " уже зарегистрирован!" << std::endl;
                    }
                    break;
                case 7:
                    if (magicCarpet->regist() && raceType != 1) {
                        results.push_back(Result{ magicCarpet->getName(), magicCarpet->getRaceTime() });
                    }
                    else if (raceType == 1) {
                        std::cout << "Нельзя зарегистрировать " << magicCarpet->getName() << " на гонку для Наземного транспорта!" << std::endl;
                    }
                    else {
                        std::cout << magicCarpet->getName() << " уже зарегистрирован!" << std::endl;
                    }
                    break;
                }
            } while (select != 0);
        }
    } while (select != 2 || results.size() < 2);

    results = sortResults(results);

    std::cout << "Таблица лидеров:" << std::endl;
    for (int i = 0; i < results.size(); ++i) {
        std::cout << i + 1 << ". " << results[i].name;
        for (int j = 0; j < 20 - results[i].name.size(); ++j) {
            std::cout << " ";
        }
        std::cout << results[i].time << std::endl;
    }

    delete allTerrainBoots;
    delete broom;
    delete camel;
    delete centaur;
    delete eagle;
    delete fastCamel;
    delete magicCarpet;
}

std::vector<Result> sortResults(std::vector<Result> results) {
    bool changed;
    do {
        changed = false;
        for (int i = 1; i < results.size(); ++i) {
            if (results[i].time < results[i - 1].time) {
                Result temp = results[i];
                results[i] = results[i - 1];
                results[i - 1] = temp;
                changed = true;
            }
        } 
    } while (changed == true);
    return results;
}