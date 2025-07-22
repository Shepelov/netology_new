#include <iostream>
#include <vector>

template <class Type>
Type sq (Type value) {
	return value * value;
}

template<>
std::vector<int> sq(std::vector<int> value) {
	std::vector<int> result;
	for(int i : value){
		result.push_back(i * i);
	}
	return result;
}

int main(int argc, char* argv[])
{
	std::cout << sq(5.0) << std::endl;
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	for (int i : sq(vec)) {
		std::cout << i << " ";
	}

	return 0;
}