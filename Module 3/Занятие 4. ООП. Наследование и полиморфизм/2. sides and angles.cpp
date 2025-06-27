#include <iostream>
#include <clocale>

class Shape {
private:
	int sides;
public:
	Shape(int sides) : sides(sides) {}
	virtual void print_info() {};
};

class Triangle : public Shape {
private:
	std::string type{ "Треугольник" };
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: Shape(3), a(a), b(b), c(c), A(A), B(B), C(C) {}
	Triangle(int a, int b, int c, int A, int B, int C, std::string type)
		: Shape(3), a(a), b(b), c(c), A(A), B(B), C(C), type(type) {}

	void print_info() override {
		std::cout << type << std::endl;
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
		std::cout << std::endl;
	}
};

class Quadangle : public Shape{
private:
	std::string type{ "Четырехугольник" };
	int a;
	int b;
	int c;
	int d;
	int A;
	int B;
	int C;
	int D;
public:
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: Shape(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}
	Quadangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string type)
		: Shape(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D), type(type) {}
	
	void print_info() override {
		std::cout << type << std::endl;
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
		std::cout << std::endl;
	}
};

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int A, int B, int C)
		: Triangle(a, b, 90, A, B, C, "Прямоугольный треугольник") {}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a)
		: Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {}
};

class Rectangle : public Quadangle {
public:
	Rectangle(int a, int b)
		: Quadangle(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {}
};

class Square : public Quadangle {
public:
	Square(int a)
		: Quadangle(a, a, a, a, 90, 90, 90, 90, "Квадрат") {}
};

class Parallelogram : public Quadangle {
public:
	Parallelogram(int a, int b, int A, int B)
		: Quadangle(a, b, a, b, A, B, A, B, "Параллелограмм") {}
};

class Rhomb : public Quadangle {
public:
	Rhomb(int a, int A, int B)
		: Quadangle(a, a, a, a, A, B, A, B, "Ромб") {}
};

void print_info(Shape* shape) {
	shape->print_info();
}

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	Triangle trg(10, 20, 30, 40, 50, 60);
	print_info(&trg);
	RightTriangle rtrg(10, 20, 30, 50, 60);
	print_info(&rtrg);
	IsoscelesTriangle itrg(10, 20, 50, 60);
	print_info(&itrg);
	EquilateralTriangle etrg(30);
	print_info(&etrg);
	Quadangle qag(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&qag);
	Rectangle rect(10, 20);
	print_info(&rect);
	Square sqw(20);
	print_info(&sqw);
	Parallelogram prlg(20, 30, 30, 40);
	print_info(&prlg);
	Rhomb rhmb(30, 30, 40);
	print_info(&rhmb);

	return 0;
}