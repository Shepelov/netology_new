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
		array = new Type* [rows];
		for (int i = 0; i < rows; ++i) {
			array[i] = new Type [columns];
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

	table& operator = (const table& other) {	
		for (int i = 0; i < rows; ++i) {
			delete[] array[i];
		}
		delete[] array;

		rows = other.rows;
		columns = other.columns;

		array = new Type* [rows];
		for (int i = 0; i < rows; ++i) {
			array[i] = new Type [columns];
		}

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				array[i][j] = other.array[i][j];
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

	//проверка валидности копирования
	auto test2 = table<int>(2, 3);
	test2 = test;
	std::cout << test2[0][0] << std::endl;

	return 0;
}