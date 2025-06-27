#include <iostream>
#include <clocale>

class Shape {
private:
	int sides;
public:
	Shape(int sides) : sides(sides) {}
	virtual void print_info() {}
	virtual bool check() {
		if (sides == 0) { return true; }
		else { return false; }
	}
	int get_sides() { return sides; }
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

	bool check() override {
		if (get_sides() == 3 && A + B + C == 180) { return true; }
		else { return false; }
	}

	void print_info() override {
		std::cout << type << std::endl;
		if (check()) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << std::endl;
		std::cout << std::endl;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
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
	
	bool check() override {
		if (get_sides() == 4 && A + B + C + D == 360) { return true; }
		else { return false; }
	}

	void print_info() override {
		std::cout << type << std::endl;
		if (check()) {
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << std::endl;
		std::cout << "Углы: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << std::endl;
		std::cout << std::endl;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }
};

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B)
		: Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {}
	bool check() override {
		if (Triangle::check() && get_C() == 90) { return true; }
		else { return false; }
	}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {}
	bool check() override {
		if (Triangle::check() && get_a() == get_c() && get_A() == get_C()) { return true; }
		else { return false; }
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a)
		: Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {}
	bool check() override {
		if (Triangle::check() && get_a() == get_b() && get_a() == get_c() && get_A() == 60 && get_B() == 60 && get_C() == 60) { return true; }
		else { return false; }
	}
};

class Rectangle : public Quadangle {
public:
	Rectangle(int a, int b)
		: Quadangle(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {}
	bool check() override {
		if (Quadangle::check() && get_a() == get_c() && get_b() == get_d() && get_A() == 90 && get_B() == 90 && get_C() == 90 && get_D() == 90) { return true; }
		else { return false; }
	}
};

class Square : public Quadangle {
public:
	Square(int a)
		: Quadangle(a, a, a, a, 90, 90, 90, 90, "Квадрат") {}
	bool check() override {
		if (Quadangle::check() && get_a() == get_b() && get_b() == get_c() && get_c() == get_d() && get_A() == 90 && get_B() == 90 && get_C() == 90 && get_D() == 90) { return true; }
		else { return false; }
	}
};

class Parallelogram : public Quadangle {
public:
	Parallelogram(int a, int b, int A, int B)
		: Quadangle(a, b, a, b, A, B, A, B, "Параллелограмм") {}
	bool check() override {
		if (Quadangle::check() && get_a() == get_c() && get_b() == get_d() && get_A() ==  get_C()  && get_B() == get_D()) { return true; }
		else { return false; }
	}
};

class Rhomb : public Quadangle {
public:
	Rhomb(int a, int A, int B)
		: Quadangle(a, a, a, a, A, B, A, B, "Ромб") {}
	bool check() override {
		if (Quadangle::check() && get_a() == get_b() && get_b() == get_c() && get_c() == get_d() && get_A() == get_C() && get_B() == get_D()) { return true; }
		else { return false; }
	}
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