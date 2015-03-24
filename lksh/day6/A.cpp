#include <iostream>

int main() {
    int s, n;
    std::cin >> s >> n;

    int c[n], w[n];

    for (int i = 0; i < n; i++)
        std::cin >> w[i];
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    int r[n][s];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < s; j++) {
            if (i == 0 || j == 0)
                r[i][j] = 0;
            else if (r[i] != 0) {
                r[i][j] = std::max(r[i - 1][j], r[i - 2][j - w[i]] + c[i]);
            }
        }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s; j++)
            std::cout << r[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}