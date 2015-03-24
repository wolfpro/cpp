#include <iostream>
#include <cstdio>

int m[1001] = {0};

int main() {
    int n, k;

    std::cin >> n >> k;

    if (n * n < k) {
        std::cout << "Impossible\n";
        return 0;
    }

    int le = 0, e = 1, p = 0, tp = 0;
    for (int i = n - 1; i > -1; i--) {
        if (k > 0) {
            p = k % n;
            if (p == 0)
                p = n - 1;
            k /= n;
            tp = 0;
            //std::cout << m[i + p]
            while (m[i - p + tp] != 0) {
                ++tp;
            }
            m[i - p + tp] = e;
            //std::cout << e << " " << i + p + tp << "\n";
            ++e;
        } else {
            tp = 0;
            while (m[le + tp] != 0) {
                ++tp;
            }
            m[le + tp] = e;
            ++e;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}