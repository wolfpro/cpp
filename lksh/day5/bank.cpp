#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

typedef long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second

const int mod = 1e9;

int main() {
    freopen("atm.in", "r", stdin);
    freopen("atm.out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    int m;
    std::cin >> m;
    std::vector<int> d(m + 1);
    d[0] = 0;
    for (int i = 1; i <= m; ++i) {
        d[i] = mod;
        for (int k = 0; k < n && i >= v[k]; ++k) {
            if (d[i] > d[i - v[k]] + 1) {
                d[i] = d[i - v[k]] + 1;
            }
        }
    }
    if (d[m] == mod) {
        std::cout << "-1\n";
        return 0;
    }
    std::cout << d[m] << "\n";

    for (int i = m; i > 0;) {
        for (int k = 0; k < n; ++k) {
            if (d[i - v[k]] == d[i] - 1) {
                std::cout << v[k] << " ";
                i -= v[k];
                break;
            }
        }
    }

    fclose(stdout);
    std::cout << "\n";
    return 0;
}