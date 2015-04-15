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

char ch[2] = {'-', '+'};

int main() {
    /*
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    */


    int n, m = 0;
    std::cin >> n;
    std::vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        m += v[i];
    }
    std::sort(v.begin(), v.end());

    m /= 2;
    std::vector<bool> ans(n + 1, 0);

    std::vector<int> d(m + 1, 0);


    d[0] = 1;
    for (int i = 1; i <= m; ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << "\n";

    for (int k = 0; k < n; ++k) {
        for (int i = m + 1; i >= 0; --i) {
            if (d[i] > 0 && i + v[k] <= m && d[i + v[k]] == 0) {
                d[i + v[k]] = k;
            }
        }
        //std::cout << 2 << '\n';
    }


    for (int i = 1; i <= m; ++i) {
        std::cout << d[i] << " ";
    }
    std::cout << "\n";

    for (int i = m; i > 0;) {
        ans[d[i]] = 1;
        i -= v[d[i]];
        // std::cout << v[d[i]] << '\n';
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ch[ans[i]];
    }
    std::cout << "\n";
    fclose(stdout);
    return 0;
}