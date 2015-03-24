#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int n, s;
std::vector<int> v;

int r(int p, int st) {
    int ans = 1;
    ans = ans << 30;
    for (int i = 1; i * v[p] <= n; ++i) {
        ans = std::min(r(p + 1, st - v[p] * i), ans);
    }
    return ans;
}

int main() {
    std::cin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    std::sort(v.rbegin(), v.rend());

    int ans = 1;
    ans = ans << 31;

    for (int i = 1; i * v[0] <= n; ++i) {
        ans = std::min(r(1, s - v[0] * i), ans);
    }

    std::cout << ans << "\n";

    return 0;
}
