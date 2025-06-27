#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void visualisation(bool** gameField, int height, int width); //вывод игрового поля на консоль
int aliveCellsAround(bool** gameField, int coordY, int coordX, int height, int width); //возвращает количество живых клеток вокруг текущей
bool cellStatus(bool** gameField, int coordY, int coordX, int height, int width); //возвращает значение текущей клетки

int main()
{
    int gameFieldHeight{};
    int gameFieldWidth{};
    vector<int> startCellsCoords;
    int aliveCells{};

    std::ifstream file {"in.txt"};
    if (file.is_open()){
        file >> gameFieldHeight;
        file >> gameFieldWidth;
        int temp;
        while (file >> temp){
            startCellsCoords.push_back(temp);
            ++aliveCells;
        }
    }
    else{
        std::cout << "Start data file not found!" << std::endl;;
        std::exit(0);
    }

    bool change{true}; //флаг внесения изменений
    int generation{1};

    //инициализируем игровое поле
    bool** gameField = new bool* [gameFieldHeight];
    bool** gameFieldLast = new bool* [gameFieldHeight];
    for (int i{}; i < gameFieldHeight; ++i){
        gameField[i] = new bool [gameFieldWidth];
        gameFieldLast[i] = new bool [gameFieldWidth];
    }
    for (int i{}; i < gameFieldHeight; ++i){
        for (int j{}; j < gameFieldWidth; ++j){
            gameField[i][j] = false;
            gameFieldLast[i][j] = false;
        }
    }

    //расставляем живые клетки из двух векторов с координатами
    for (int i{}; i < static_cast<int>(startCellsCoords.size()/2); ++i){
        gameField[startCellsCoords[i*2]][startCellsCoords[i*2+1]] = true;
    }

    visualisation(gameField, gameFieldHeight, gameFieldWidth);
    std::cout << "Generation: " << generation << ". Alive cells: " << aliveCells << std::endl;
    sleep(1);

    while(change == true && aliveCells > 0){
        for (int i{}; i < gameFieldHeight; ++i){
            for (int j{}; j < gameFieldWidth; ++j){
                gameFieldLast[i][j] = gameField[i][j];
            }
        }

        std::system("cls");
        change = false;
        for(int i{}; i < gameFieldHeight; ++i){
            for(int j{}; j < gameFieldWidth; ++j){
                if(gameFieldLast[i][j]){
                    if(aliveCellsAround(gameFieldLast, i, j, gameFieldHeight, gameFieldWidth) < 2 || aliveCellsAround(gameFieldLast, i, j, gameFieldHeight, gameFieldWidth) >3){
                        gameField[i][j] = false;
                        change = true;
                    }
                }
                else{
                    if(aliveCellsAround(gameFieldLast, i, j, gameFieldHeight, gameFieldWidth) == 3){
                        gameField[i][j] = true;
                        change = true;
                    }
                }
            }
        }
        ++generation;
        aliveCells = 0;
        for (int i{}; i < gameFieldHeight; ++i){
            for (int j{}; j < gameFieldWidth; ++j){
                if(gameField[i][j]) ++aliveCells;
            }
        }
        visualisation(gameField, gameFieldHeight, gameFieldWidth);
        std::cout << "Generation: " << generation << ". Alive cells: " << aliveCells << std::endl;
        sleep(1);
    }

    if(aliveCells == 0){
        std::cout << "All cells are dead! Game over!";
    };
    if(change == false){
        std::cout << "The world has stagnated! Game over!";
    }

    for (int i{}; i < gameFieldHeight; ++i){
        delete[] gameField[i];
        delete[] gameFieldLast[i];
    }
    delete[] gameField;
    delete[] gameFieldLast;

    return 0;
}

void visualisation (bool** gameField, int height, int width){
    for (int i{}; i < height; ++i){
        for (int j{}; j < width; ++j){
            if(gameField[i][j]){
                std::cout << "*";
            }
            else{
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}

int aliveCellsAround(bool** gameField, int coordY, int coordX, int height, int width){
    int counter{0};
    if(cellStatus(gameField, coordY - 1, coordX - 1, height, width)) ++counter;
    if(cellStatus(gameField, coordY - 1, coordX, height, width)) ++counter;
    if(cellStatus(gameField, coordY - 1, coordX + 1, height, width)) ++counter;
    if(cellStatus(gameField, coordY, coordX - 1, height, width)) ++counter;
    if(cellStatus(gameField, coordY, coordX + 1, height, width)) ++counter;
    if(cellStatus(gameField, coordY + 1, coordX - 1, height, width)) ++counter;
    if(cellStatus(gameField, coordY + 1, coordX, height, width)) ++counter;
    if(cellStatus(gameField, coordY + 1, coordX + 1, height, width)) ++counter;
    return counter;
}

bool cellStatus(bool** gameField, int coordY, int coordX, int height, int width){
    if (coordX < 0 || coordY < 0 || coordX > width - 1 || coordY > height - 1){
        return false; // если выходим за границы переданного массива, возвращаем false
    }
    else return gameField[coordY][coordX];
}
