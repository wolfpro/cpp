#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cassert>
#include <string>

#define FF first
#define SS second

typedef unsigned long long LL;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    s = -1;
    while (s < n - 1) {
        if (v[s + 1] > v[s + 2])
            s++;
        else
            s += 2;
        ans += v[s];
    }
    if (s != n - 1) {
        s++;
        ans += v[s];
    }

    std::cout << ans << "\n";

    return 0;
}