#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

std::vector<std::pair<char, int>> sort_map(std::unordered_map<char, int> map) {
	std::vector<std::pair<char, int>> vector;
	for (std::pair<char, int> i : map) {
		vector.push_back(i);
	}

	bool swaped;
	do {
		swaped = false;
		for (int i = 0; i < vector.size() - 1; ++i) {
			if (vector[i].second < vector[i + 1].second) {
				std::pair<char, int> temp = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = temp;
				swaped = true;
			}
		}
	} while (swaped);

	return vector;
}

void print_vector(std::vector<std::pair<char, int>> vector) {
	for (std::pair<char, int> i : vector) {
		std::cout << i.first << ": " << i.second << std::endl;
	}
}

int main(int argc, char* argv[])
{
	std::unordered_map<char, int> input_map;
	std::string input_text;

	std::cout << "[IN]: ";
	std::getline(std::cin, input_text);
	for (char i : input_text) {
		if (input_map.count(i) == 0) {
			input_map.insert(std::pair<char, int>(i, 1));
		}
		else {
			++input_map[i];
		}
	}

	std::vector<std::pair<char, int>> sorted_vector = sort_map(input_map);

	std::cout << "[OUT]: " << std::endl;
	print_vector(sorted_vector);

	return 0;
}