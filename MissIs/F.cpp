#include <iostream>
#include <cstdio>

int m[1001] = {0};

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int ans = k - n + 1;
    if (k - m >= 0) {
        ans = ans + k - m + 1;
    }

    if (ans > 0)
        std::cout << ans << std::endl;
    else {
        std::cout << 0 << std::endl;
    }
    return 0;
}