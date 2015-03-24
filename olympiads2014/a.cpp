#include <iostream>

int f[200 * 1000 + 2];
int df[200 * 1000 + 2];

int per[200 * 1000 + 2];


int main() {
    std::ios_base::sync_with_stdio(false);

    unsigned long long n;
    std::cin >> n;

    int c, tc = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> c;
        df[i] = c;
        tc = std::max(tc, c);
        f[i] = tc;
        per[i + 1] = std::min(tc, c);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << f[i] << " ";
    }
    std::cout << "\n";

    unsigned long long k;
    std::cin >> k;

    while (k) {
        std::cin >> c;
        --c;
        std::cout << f[c % (n - 1)] << " " << df[c % (n - 1) + 1] << " ";
        --k;
    }
    std::cout << '\n';

    return 0;
}