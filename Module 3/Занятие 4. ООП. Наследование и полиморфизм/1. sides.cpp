#include <iostream>
#include <clocale>

class Figure{
private:
	int sides;
public:
	Figure() : sides(0){}
	Figure(int s) : sides(s){}
	int getSides(){
		return sides;
	}
};

class Triangle : public Figure{
public:
	Triangle() : Figure(3){}
};

class Rectangle : public Figure{
public:
	Rectangle() : Figure(4){}
};

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	Figure figure;
	Triangle triangle;
	Rectangle rectangle;

	std::cout << "Количество сторон: " << std::endl;
	std::cout << "Фигура: " << figure.getSides() << std::endl;
	std::cout << "Треугольник: " << triangle.getSides() << std::endl;
	std::cout << "Четырехугольник: " << rectangle.getSides() << std::endl;

	return 0;
}