#include <iostream>

void swap (int* a, int* b);

int main(int argc, char** argv){
    int a = 6;
    int b = 9;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(&a, &b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
}

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
