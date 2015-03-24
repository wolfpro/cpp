#include <iostream>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;
    if (n < k) {
        std::cout << n << std::endl;
    } else
        std::cout << n % 2 << std::endl;

    return 0;
}