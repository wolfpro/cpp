#include <iostream>

bool num[10 * 1000 * 1003];

int main() {
    long long l, r;
    std::cin >> l >> r;

    for (int i = 2; i * i <= r; ++i) {
        if (num[i] == 0)
            for (int j = 2; j * i <= r; ++j) {
                num[i * j] = 1;
            }
    }
    num[2] = 0;
    num[1] = 1;

    long long la = 0, lb = 0;
    for (int i = l; i <= r; ++i) {
        if (num[i] == 0) {
            la++;
        }
    }
    std::cout << la << std::endl;

    return 0;
}