#include <iostream>

int main() {
    int n;

    std::cin >> n;
    int a ;
    std::cin >> a;
    for (int i = 1; i < n; ++i) {
        int t;
        std::cin >> t;
        a = (a ^ t);
    }

    std::cout << a  << std::endl;

    return 0;
}