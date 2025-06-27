#include <iostream>
#include <clocale>

class Calculator{
private:
	double num1;
	double num2;
public:
	bool set_num1(double num1){
		if(num1 !=0){
			this->num1 = num1;
			return true;
		}
		else{
			return false;
		}
	}

	bool set_num2(double num2){
		if(num2 !=0){
			this->num2 = num2;
			return true;
		}
		else{
			return false;
		}
	}

	double get_num1(){
		return num1;
	}

	double get_num2(){
		return num2;
	}

	double add(){
		return num1 + num2;
	}

	double multiply(){
		return num1 * num2;
	}

	double subtract_1_2(){
		return num1 - num2;
	}

	double subtract_2_1(){
		return num2 - num1;
	}

	double divide_1_2(){
		return num1 / num2;
	}

	double divide_2_1(){
		return num2 / num1;
	}
};

int main(int argc, char argv[])
{
	setlocale(LC_ALL, "rus");

	Calculator calc;
	double num;

	while (true){
		do{
			std::cout << "Введите первое число: ";
			std::cin >> num;
			if (!calc.set_num1(num)){
				std::cout << "Неверный ввод!" << std::endl;
			}	
		}
		while (!calc.set_num1(num));

		do{
			std::cout << "Введите второе число: ";
			std::cin >> num;
			if (!calc.set_num2(num)){
				std::cout << "Неверный ввод!" << std::endl;
			}	
		}
		while (!calc.set_num2(num));

		std::cout <<  calc.get_num1() << " + " << calc.get_num2() << " = " << calc.add() << std::endl;
		std::cout <<  calc.get_num1() << " - " << calc.get_num2() << " = " << calc.subtract_1_2() << std::endl;
		std::cout <<  calc.get_num2() << " - " << calc.get_num1() << " = " << calc.subtract_2_1() << std::endl;
		std::cout <<  calc.get_num1() << " * " << calc.get_num2() << " = " << calc.multiply() << std::endl;
		std::cout <<  calc.get_num1() << " / " << calc.get_num2() << " = " << calc.divide_1_2() << std::endl;
		std::cout <<  calc.get_num2() << " / " << calc.get_num1() << " = " << calc.divide_2_1() << std::endl;
		std::cout << std::endl;
	}

	return 0;
}

