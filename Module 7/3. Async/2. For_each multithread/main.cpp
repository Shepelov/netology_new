#include <vector>
#include <iostream>
#include <iterator>
#include <future>

std::vector<int> create_random_vector(int size, int max) { 
    std::vector<int> list;
    for (int i = 0; i < size; ++i) {
        list.push_back(rand() % max + 1);
    }
    return list;
}

void print_list(std::vector<int> list) {
    for (int value : list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

template<typename F>
void for_each_mth(std::vector<int>::iterator begin, std::vector<int>::iterator end, F func) {
    if (std::distance(end, begin) > 1) {
        std::vector<int>::iterator mid = std::next(begin, std::distance(begin, end) / 2);
        std::future<void> f1 = std::async(&for_each_mth<F>, begin, mid, func);
        std::future<void> f2 = std::async(&for_each_mth<F>, mid, end, func);
    }
    else {
        std::for_each(begin, end, func);
    }
}

int main(){
    srand(time(0));
    std::vector<int> vec = create_random_vector(10, 50);
    std::cout << "Vector before calculatings:" << std::endl;
    print_list(vec);
    for_each_mth(vec.begin(), vec.end(), [](int& value) {value = value + 10; });
    std::cout << "Vector after calculatings:" << std::endl;
    print_list(vec);

    return 0;
}