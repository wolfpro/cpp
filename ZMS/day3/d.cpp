#include <iostream>

long long n, k;

int main() {

    std::cin >> n >> k;
    long long ans = 0;
    long long p[n], d[n];

    for (long long i = 0; i < n; ++i) {
        std::cin >> p[i];
        d[i] = 0;
    }

    for (int in1 = 0, in2 = 1; in1 < n - 1; ++in1) {
        while (p[in1] + k >= p[in2]) {
            if (in2 >= n) {
                in2 = n;
                break;
            }
            in2++;
        }
        if (in2 >= n) {
            in2 = n - 1;
        }
        if (p[in1] + k < p[in2]) {
            ans += (n - in2);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}