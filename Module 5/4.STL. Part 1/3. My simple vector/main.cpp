#include <iostream>

template <class T>
class my_vector {
private:
	T* array;
	int vec_size;
	int vec_capacity;
public:
	my_vector(int amount) {
		array = new T[amount];
		vec_size = 0;
		vec_capacity = amount;
	}

	~my_vector()
	{
		delete[] array;
	} 

	T at(int index) {
		return array[index];
	}

	void push_back(T value) {
		if (vec_size == vec_capacity) {
			vec_capacity *= 2;
			T* temp = new T[vec_capacity];
			for (int i = 0; i < vec_size; ++i) {
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
		}
		array[vec_size] = value;
		++vec_size;
	}

	int size() {
		return vec_size;
	}

	int capacity() {
		return vec_capacity;
	}
};

void print_info(my_vector<int>* vector) {		//вспомогательная функция для вывода size и capacity
	std::cout << "Size: " << vector->size() << ", Capacity: " << vector->capacity() << std::endl;
}

int main(int argc, char* argv[])				//тест работы вектора
{
	my_vector<int> vec(3);
	print_info(&vec);
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(17);
	print_info(&vec);
	vec.push_back(27);
	print_info(&vec);
	vec.push_back(80);
	vec.push_back(80);
	vec.push_back(80);
	vec.push_back(80);
	vec.push_back(80);
	vec.push_back(80);
	print_info(&vec);
	std::cout << vec.at(3) << std::endl;

	return 0;
}