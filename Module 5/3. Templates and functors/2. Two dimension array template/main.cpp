#include <iostream>

template <class Type>
class table {
private:
	Type** array;
	int rows;
	int columns;
public:
	table(int a, int b) {
		rows = a;
		columns = b;
		array = new Type* [a];
		for (int i = 0; i < a; ++i) {
			array[i] = new Type[b];
		}
	}

	~table() {
		for (int i = 0; i < rows; ++i) {
			delete[] array[i];
		}
		delete[] array;
	}

	Type* operator [] (int index) {
		return array[index];
	}

	Type* operator [] (int index) const {
		return array[index];
	}

	Type* operator = (const Type* operand) {
		for (int i = 0; i < rows; ++i) {
			delete[] array[i];
		}
		delete[] array;

		array = new Type* [operand->rows];
		for (int i = 0; i < operand->rows; ++i) {
			array[i] = new Type[operand->columns];
		}

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				array[i][j] = operand->array[i][j];
			}
		}
		return *this;
	}
};


int main(int argc, char* argv[])
{
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0] << std::endl;

	//проверка валидности присваивания
	auto test2 = table<int>(2, 3);
	test2 = test;
	std::cout << test2[0][0] << std::endl;

	return 0;
}