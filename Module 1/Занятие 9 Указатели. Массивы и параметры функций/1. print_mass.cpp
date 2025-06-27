#include <iostream>

void print (int* mass, int massSize);

int main(int argc, char** argv){
int mass1[] {4, 6, 7, 3, 6, 7, 8, 6, 9, 13};
int mass2[] {2, 5, 6, 7};
int mass3[] {8, 5, 2, 0, 1, 7};
int massSize1 {sizeof (mass1) / sizeof (int)};
int massSize2 {sizeof (mass2) / sizeof (int)};
int massSize3 {sizeof (mass3) / sizeof (int)};

print (mass1, massSize1);
print (mass2, massSize2);
print (mass3, massSize3);
}

void print (int* mass, int massSize){
    for (int element{}; element < massSize; ++element){
        std::cout << mass[element] << " ";
    }
    std::cout << std::endl;
}
