#include <iostream>
#include <set>
#include <algorithm>

void print_set_reverse(std::set<int> set) {
	std::reverse_copy(set.begin(), set.end(), std::ostream_iterator<int>(std::cout, "\n"));
}

int main(int argc, char* argv[])
{
	std::set<int> numbers;
	int amount;

	std::cout << "[IN]:" << std::endl;
	std::cin >> amount;
	for (int i = 0; i < amount; ++i) {
		int value;
		std::cout << "Enter the value " << i << ": ";
		std::cin >> value;
		numbers.insert(value);
	}

	std::cout << "[OUT]:" << std::endl;
	print_set_reverse(numbers);

	return 0;
}