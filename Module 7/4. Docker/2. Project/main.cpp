#include <iostream>

int main()
{
    std::cout << "Operator ||" << std::endl << std::boolalpha;
    std::cout << "false\tfalse\t" << (false||false) << std::endl;
    std::cout << "false\ttrue\t" << (false||true) << std::endl;
    std::cout << "true\tfalse\t" << (true||false) << std::endl;
    std::cout << "true\ttrue\t" << (true||true) << std::endl;

    std::cout << std::endl << "Operator &&" << std::endl;
    std::cout << "false\tfalse\t" << (false&&false) << std::endl;
    std::cout << "false\ttrue\t" << (false&&true) << std::endl;
    std::cout << "true\tfalse\t" << (true&&false) << std::endl;
    std::cout << "true\ttrue\t" << (true&&true) << std::endl;

    return 0;
}
