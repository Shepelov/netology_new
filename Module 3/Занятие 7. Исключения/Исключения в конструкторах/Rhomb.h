#ifndef RHOMB_H
#define RHOMB_H

class Rhomb : public Quadangle {
public:
	Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadangle(a, a, a, a, A, B, A, B, "Ромб") {
		if (a != b && a != c && a != d) {
			throw GeometryException("Стороны a, b, c и d не равны друг другу!");
		}
		else if (A != C && B != D) {
			throw GeometryException("Углы A и C, B и D попарно не равны!");
		}
		else {
			std::cout << "Ромб (стороны: " << a << " " << b << " " << c << " " << d << ", углы: " << A << " " << B << " " << C << " " << D << ") создан" << std::endl;
		}
	}
};

#endif