#include <iostream>

int main() {
    long long n, ans = 0;
    std::cin >> n;

    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0)
            ans += 2;
        if (i * i == n) {
            ans--;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}