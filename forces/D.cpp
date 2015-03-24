#include <iostream>

void no() {
    std::cout << "NO\n";
}

void yes() {
    std::cout << "YES\n";
}

int main() {
    int n = 0;
    std::cin >> n;
    int m[n][n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> m[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            if ((i == j && m[i][j] != 0) || (m[i][j] != m[j][i])) {
                no();
                return 0;
            }
        }
    yes();


    return 0;
}