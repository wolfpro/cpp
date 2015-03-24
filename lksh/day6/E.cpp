#include <iostream>
#include <string>
#include <cstdio>

int main() {
    freopen("interference.in", "r", stdin);
    freopen("interference.out", "w", stdout);

    int n1, n2;
    std::cin >> n1;

    std::string a;
    std::cin >> a;

    std::cin >> n2;

    std::string b;
    std::cin >> b;

    int r[n1 + 1][n2 + 1];

    for (int i = 0; i < n1 + 1; i++) {
        r[i][0] = i;
    }

    for (int i = 0; i < n2 + 1; i++) {
        r[0][i] = i;
    }

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (a[i - 1] == b[j - 1]) {
                r[i][j] = r[i - 1][j - 1];
            } else {
                r[i][j] = std::min(r[i - 1][j], std::min(r[i][j - 1], r[i - 1][j - 1])) + 1;
            }
        }
    }

    std::cout << r[n1][n2] << std::endl;

    fclose(stdout);
    return 0;
}