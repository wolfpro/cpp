#include <iostream>

long long v[11][11];
int main() {
    int n, m;
    std::cin >> n >> m;
    v[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        v[i][0] = 1;
    }
    for (int i = 0; i < m; ++i) {
        v[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            v[i][j] = v[i][j - 1] + v[i - 1][j];
        }
    }

    std::cout << v[n - 1][m - 1] << "\n";

    return 0;
}