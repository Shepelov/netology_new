#include <iostream>
int a{};
int b{};

void swap (int a, int b){
    ::a = b;
    ::b = a;
}

int main(int argc, char** argv)
{
    a = 5, b = 8;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    swap(a, b);

    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
