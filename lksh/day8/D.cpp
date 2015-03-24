#include <iostream>
#include <algorithm>
#include <cstdio>

long long tp[65][65];

int main() {
    freopen("combination.in", "r", stdin);
    freopen("combination.out", "w", stdout);

    long long n, k;
    std::cin >> n >> k;

    for (long long i = 0; i <= n; i++) {
        for (long long j = 0; j <= i; j++) {
            if (i == j || i == 0) {
                tp[i][j] = 1;
            } else
                tp[i][j] = tp[i - 1][j - 1] + tp[i - 1][j];
            // std::cout <<  tp[i][j] << " ";
        }
        //  std::cout << std::endl;
    }
    std::cout << tp[n][k] << std::endl;

    fclose(stdout);
    return 0;
}

