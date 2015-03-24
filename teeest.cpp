#include <iostream>
#include <ctime>

int main() {
    std::ios_base::sync_with_stdio(false);
    for (int i = 0; i < 5e8; ++i);
    std::cout << (double) clock() * 1.0 / CLOCKS_PER_SEC;
}