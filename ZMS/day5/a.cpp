#include <iostream>

int main() {
    bool lp = false;
    char c;

    while (1) {
        std::cin >> c;
        if (c == '.')
            break;

        if (c >= '0' && c <= '9') {
            lp = true;
            std::cout << c;
        } else {
            if (lp) {
                std::cout << std::endl;
                lp = false;
            }
            std::cout << c;
            std::cout << std::endl;
        }
    }

    return 0;
}