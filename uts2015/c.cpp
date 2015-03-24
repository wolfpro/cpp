#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

const long long  SIZE = 1e7 + 1;

bool m[SIZE];

long long  main() {
    freopen("parade.in", "r", stdin);
    freopen("parade.out", "w", stdout);
    for (long long  i = 2; i * i < SIZE; ++i) {
        for (long long  j = i; j * i < SIZE; ++j) {
            m[i * j] = 1;
        }
    }

    std::vector<long long > p;
    for (long long  i = 2; i < SIZE; ++i) {
        if (!m[i]) {
            p.push_back(i);
        }
    }

    long long  k, n;
    std::cin >> k >> n;

    if (k > n * n || k > p.size()) {
        std::cout << "-1\n";
        return 0;
    }

    long long  f[1000][1000];

    std::vector<long long > v(n);
    for (long long  i = 0; i < std::min(n, k); ++i)
        v[i] = p[i];
    for (long long  i = std::min(n, k); i < n; ++i)
        v[i] = v[std::min(n, k) - 1];

    for (long long  i = 0; i < n; ++i) {
        for (long long  j = 0; j < n; ++j)
            f[i][j] = v[(i + j) % n];
    }

    for (long long  i = 1; i < n; ++i) {
        for (long long  j = 0; j + n * i < k; ++j)
            f[i][j] = p[j + n * i];
    }

    for (long long  i = 0; i < n; ++i) {
        for (long long  j = 0; j < n; ++j)
            std::cout << f[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}