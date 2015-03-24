#include <iostream>

int main() {
    unsigned int a, k;
    std::cin >> a >> k;

    std::cout << ((((1 << k)&a)) >> k) << std::endl;
    std::cout << ((1 << k) | a) << std::endl;
    std::cout << (~(1 << k) & a) << std::endl;
    std::cout << ((1 << k) ^ a) << std::endl;

    unsigned int b = -1;
    b = b << k;
    std::cout << (a & b) << std::endl;
    b = ~b;
    std::cout << (a & b) << std::endl;
    return 0;
}