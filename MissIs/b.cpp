#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cassert>

#define FF first
#define SS second

typedef long long LL;

int main() {
    int n;
    std::cin >> n;
    std::vector<LL> v(n + 1, 0);
    v[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i + j + 1 <= n) {
                v[i + j + 1] += v[i];
            }
        }
    }

    std::cout << v[n] << '\n';
    return 0;
}