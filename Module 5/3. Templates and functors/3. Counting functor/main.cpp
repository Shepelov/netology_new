#include <iostream>
#include <vector>
#include <algorithm>

class Counter {
private:
	int sum;
	int count;
public:
	Counter() : sum{ 0 }, count{ 0 } {}
	void operator() (std::vector<int> value) {
		for (int i : value) {
			if (i % 3 == 0) {
				sum += i;
				++count;
			}
		}
	}

	int get_sum() {
		return sum;
	}

	int get_count() {
		return count;
	}
};

int main(int argc, char* argv[])
{
	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());
	std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

	return 0;
}