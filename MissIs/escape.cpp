#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
#define puba push_back
const int mod = 1e9 + 7;

int main() {
    LL n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > v(n);
    std::vector<std::vector<LL> > p(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(m);
        p[i].resize(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> v[i][j];
        }
    }

    p[0][0] = v[0][0];
    for (int i = 1; i < n; ++i)
        p[i][0] += p[i - 1][0] * v[i][0];

    for (int i = 1; i < m; ++i)
        p[0][i] += p[0][i - 1] * v[0][i];

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            p[i][j] = (p[i - 1][j] + p[i][j - 1]) * v[i][j];
        }
    }
    if (p[n - 1][m - 1] > 0)
        std::cout << p[n - 1][m - 1] << "\n";
    else
        std::cout << "Impossible\n";
    return 0;
}