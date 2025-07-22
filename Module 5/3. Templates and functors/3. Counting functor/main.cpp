#include <iostream>
#include <vector>

class counter {
private:
	int sum;
	int count;
public:
	counter() : sum{ 0 }, count{ 0 } {}
	void operator() (std::vector<int> value) {
		for (int i : value) {
			if (i % 3 == 0) {
				sum += i;
				++count;
			}
		}
		std::cout << "get_sum() = " << sum << std::endl;
		std::cout << "get_count() = " << count << std::endl;
	}
};

int main(int argc, char* argv[])
{
	std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };
	counter cnt;
	cnt(vec);

	return 0;
}