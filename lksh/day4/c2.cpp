#include <vector>
#include <iostream>
#include <cstdio>

#define pub push_back
#define ff first
#define ss second

int main() {
    freopen("pdd.in", "r", stdin);
    freopen("pdd.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;
    int f[n][m];
    int din[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> f[i][j];
            din[i][j] = 0;
        }
    }

    din[0][0] = f[0][0];
    for (int i = 1; i < n; ++i) {
        din[i][0] = din[i - 1][0] + f[i][0];
    }
    for (int i = 1; i < m; ++i) {
        din[0][i] = din[0][i - 1] + f[0][i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            din[i][j] = std::min(din[i - 1][j], din[i][j - 1]) + f[i][j];
        }
    }

    int x = n - 1, y = m - 1;
    std::vector<std::pair <int, int > > v;
    v.pub(std::make_pair(x, y));

    while (x || y) {
        if (x > 0 && y > 0 ) {
            if (din[x - 1][y] < din[x][y - 1]) {
                x--;
            } else
                y--;
        } else {
            if (x > 0)
                x--;
            else
                y--;
        }
        v.pub(std::make_pair(x, y));
    }

    std::cout << din[n - 1][m - 1] << '\n';
    std::cout << v.size() << '\n';

    for (int i = v.size(); i > 0; --i) {
        std::cout << v[i - 1].ff + 1 << " " << v[i - 1].ss + 1 << "\n";
    }

    fclose(stdout);
    return 0;
}