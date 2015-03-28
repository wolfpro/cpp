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

    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    std::vector<int> ans(n);
    ans[0] = v[0];
    ans[1] = v[1];
    for (int i = 2; i < n; ++i) {
        ans[i] = std::min(ans[i - 1], ans[i - 2]) + v[i];
    }


    std::cout << ans[n - 1] << "\n";

    return 0;
}