#include <iostream>
#include <cstdio>

#define INF 1000*1000*1000


int main() {
    freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);

    int n;
    std::cin >> n;

    int m[n + 1][n + 1];
    int d[n + 1][n + 1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1, a; j <= n; ++j) {
            std::cin >> a;
            a;
            m[i][j] = a;
            d[i][j] = a;
        }
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << d[i][j] << " ";
        }
        std::cout << std::endl;
    }

    fclose(stdout);
    return 0;
}