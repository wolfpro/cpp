#include <iostream>
#include <vector>

int main() {

    std::vector<short> num(7001);
    num[0] = 1;
    int a, n, len = 1;
    std::cin >> a >> n;
    while (n > 0) {
        int cur = 0;
        for (int i = 0; i < len; ++i) {
            cur += num[i] * a;
            num[i] = cur % 10;
            cur /= 10;
        }
        while (cur > 0) {
            num[len++] = cur % 10;
            cur /= 10;
        }
        --n;
    }

    for (int i = len; i > 0; --i) {
        std::cout << num[i - 1];
    }
    std::cout << '\n';

    return 0;
}