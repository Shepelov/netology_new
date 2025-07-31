#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> unique_vector(std::vector<int> vector) {
	std::sort(vector.begin(), vector.end());
	vector.erase(std::unique(vector.begin(), vector.end()), vector.end());

	return vector;
}

void print_vector(std::vector<int> vector) {
	for (int i : vector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };

	std::cout << "[IN]: ";
	print_vector(vec);
	std::cout << "[OUT]: ";
	print_vector(unique_vector(vec));

	return 0;
}
