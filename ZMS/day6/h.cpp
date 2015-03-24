#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a % 2 == 0) {
        std::cout << "YES\n";
        std::cout << a / 2 << std::endl;
        return 0;
    }

    if ((b - a) % 2 == 0) {
        std::cout << "YES\n";
        std::cout << ((a + b) / 2) % b << std::endl;
    } else {
        std::cout << "NO\n";
    }


    return 0;
}