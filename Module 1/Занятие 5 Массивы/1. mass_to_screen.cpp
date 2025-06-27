#include <iostream>
#include <windows.h>
#include <clocale>

int main()
{
    int array[] {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int array_size = sizeof (array) / sizeof (array[0]);

    for (int i{}; i<array_size; ++i){
        std::cout << array[i];
        if (i == array_size-1) continue;
        std::cout << ", ";
    }

    return 0;
}
