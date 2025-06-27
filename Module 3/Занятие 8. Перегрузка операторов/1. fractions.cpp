#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	double decimal(const Fraction& fraction) const
	{
		return (static_cast<double>(fraction.numerator_) / fraction.denominator_);
	}
public:
	Fraction(int numerator, int denominator) :
		numerator_ (numerator),
		denominator_ (denominator)
		{}

	bool operator == (Fraction right) {
		return (decimal(*this) == decimal(right));
	}

	bool operator < (Fraction right) {
		return (decimal(*this) < decimal(right));
	}

	bool operator > (Fraction right) {
		return !(decimal(*this) == decimal(right)) && !(decimal(*this) < decimal(right));
	}

	bool operator != (Fraction right) {
		return !(decimal(*this) == decimal(right));
	}

	bool operator <= (Fraction right) {
		return (decimal(*this) == decimal(right)) || (decimal(*this) < decimal(right));
	}

	bool operator >= (Fraction right) {
		return !(decimal(*this) < decimal(right));
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << (!(f1 == f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << (!(f1 < f2) && !(f1 == f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) || (f1 == f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << (!(f1 < f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}