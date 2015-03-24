#include <iostream>
#include <vector>
#include <cstdio>

int f[101][101], top;

int main() {
    freopen("complete.in", "r", stdin);
    freopen("complete.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;

    for (int i = 0, a, b; i < m; i++) {
        std::cin >> a >> b;
        a--;
        b--;
        if (f[a][b] == 0)
            top++;
        if (f[b][a] == 0)
            top++;

        f[a][b]++;
        f[b][a]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && f[i][j] == 0) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "YES" << std::endl;

    fclose(stdout);
    return 0;
}