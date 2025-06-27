#include <iostream>

int main()
{
    int variableInt{};
    short variableShort{};
    long variableLong{};
    long long variableLongLong{};
    float variableFloat{};
    double variableDouble{};
    long double variableLongDouble{};
    bool variableBool{};

    std::cout << "int:        \t" << &variableInt << "\t" << sizeof (variableInt) << std::endl;
    std::cout << "short:      \t" << &variableShort << "\t" << sizeof (variableShort) << std::endl;
    std::cout << "long:       \t" << &variableLong << "\t" << sizeof (variableLong) << std::endl;
    std::cout << "long long:  \t" << &variableLongLong << "\t" << sizeof (variableLongLong) << std::endl;
    std::cout << "float:      \t" << &variableFloat << "\t" << sizeof (variableFloat) << std::endl;
    std::cout << "double:     \t" << &variableDouble << "\t" << sizeof (variableDouble) << std::endl;
    std::cout << "long double:\t" << &variableLongDouble << "\t" << sizeof (variableLongDouble) << std::endl;
    std::cout << "bool:       \t" << &variableBool << "\t" << sizeof (variableBool) << std::endl;


    return 0;
}
