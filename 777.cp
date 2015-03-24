#include <iostream>

int main() {
    int t = 777;
    for (int i = 31; i >= 0; --i) {
        std::cout << (t >> i & 1);
    }
    std::cout << std::endl;

    return 0;
}