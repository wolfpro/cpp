#include <iostream>
#include <cstdio>

int g[101][101];
int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j && g[i][j] != 0 || (g[i][j] != g[j][i])) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    std::cout << "YES" << std::endl;

    fclose(stdout);
    return 0;
}