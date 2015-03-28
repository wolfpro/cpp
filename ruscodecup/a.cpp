#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
#define puba push_back

void sol() {
    int n, l;
    std::cin >> n >> l;
    std::vector<int> g(n);
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> d[i];
    }
    std::sort(g.begin(), g.end());
    std::sort(d.rbegin(), d.rend());

    int s1 = 0, s2 = 0;
    for (int i = 0; i < l; ++i) {
        s1 += g[i];
        s2 += d[i];
    }
    if (s1 > s2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t > 0) {
        sol();
        --t;
    }

    return 0;
}