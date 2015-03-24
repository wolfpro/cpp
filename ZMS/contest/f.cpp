#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if ((a == 1 && b == 1) || a == 2 && b == 2 || (a == b && a % 2 == 1)) {
        std::cout << "FIRST\n";
        return 0;
    }

    if ((a == 1 && b % 2 == 0) || (b == 1 && a % 2 == 0) ) {
        std::cout << "FIRST\n";
        return 0;
    }
    if (a == 1 && b % 2 == 1 || (b == 1 && a % 2 == 1) ) {
        std::cout << "SECOND\n";
        return 0;
    }


    if (a == b) {
        std::cout << "SECOND\n";
    } else {
        std::cout << "FIRST\n";
    }


    return 0;
}