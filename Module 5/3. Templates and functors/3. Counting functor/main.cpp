#include <iostream>
#include <unordered_map>
#include <algorithm>


int main(int argc, char* argv[])
{
	std::unordered_map<char, int> input_map;
	std::string input_text;

	std::cout << "[IN]: ";
	std::cin >> input_text;
	for (char i : input_text) {
		if (input_map.count(i) == 0) {
			input_map.insert(std::pair(i, 1));
		}
		else {
			++input_map[i];
		}
	}


	return 0;
}