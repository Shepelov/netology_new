#include <iostream>
#include <vector>
#include <utility>

void move_vectors(std::vector<std::string>& vec1, std::vector<std::string>& vec2) {
    vec2 = std::move(vec1);
}

void print_vector(std::vector<std::string> vec, std::string name) {     //функция для тестирования
    std::cout << name << ": ";
    if (vec.size() != 0) {
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << "; ";
            }
        }
    }
    else {
        std::cout << "[empty]";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    
    //тест функции
    std::cout << "BEFORE MOVE:" << std::endl;
    print_vector(one, "one");
    print_vector(two, "two");

    move_vectors(one, two);

    std::cout << std::endl;
    std::cout << "AFTER MOVE:" << std::endl;
    print_vector(one, "one");
    print_vector(two, "two");

    return 0;
}