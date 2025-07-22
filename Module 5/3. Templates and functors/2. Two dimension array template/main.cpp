#include <iostream>

template <class Type>
class table {
private:
	Type** array;
	int rows;
public:
	table (int a, int b) {
		rows = a;
		array = new int* [a];
		for (int i = 0; i < a; ++i) {
			array[i] = new int[b];
		}
	}
	~table () {
		for (int i = 0; i < rows; ++i) {
			delete[] array[i];
		}
		delete[] array;
	}

	Type* operator[](int index) {
		return array[index];
	}

	Type* operator[](int index) const {
		return array[index];
	}
};


int main(int argc, char* argv[])
{
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0];

	return 0;
}