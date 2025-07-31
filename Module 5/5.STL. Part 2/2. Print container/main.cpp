#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>

template <class T>
void print_container(T container) {
	for (const auto& i : container) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set);

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list);

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector);

	return 0;
}