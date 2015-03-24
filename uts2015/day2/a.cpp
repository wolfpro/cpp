#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    std::vector<bool> v(2 * n);
    for (int i = 0; i < n; ++i) {
        v[i] = 1;
        v[n + i] = 0;
    }
    int ans = n;

    for (int i = 0, a, b; i < m; ++i) {
        std::cin >> a >> b;
        --a, --b;
        int t = a;
        a = std::min(t, b);
        b = std::max(t, b);

        if (v[a] != v[b])
            if ((a < n) && (b >= n)) {
                if (v[a]) {
                    --ans;
                }
                else
                    ++ans;
            }
        // std::swap(v[a], v[b]);
        bool tt = v[a];
        v[a] = v[b];
        v[b] = tt;

        std::cout << ans << '\n';
    }
    return 0;
}