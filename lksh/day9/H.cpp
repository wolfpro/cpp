#include <iostream>
#include <vector>
#include <cstdio>

int in[101];
int ou[101];

int main() {
    freopen("source.in", "r", stdin);
    freopen("source.out", "w", stdout);

    int n;
    std::cin >> n;
    int g[n][n];

    int a = n, b = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
            if (g[i][j] == 1) {
                if (ou[j] == 0)
                    a--;
                ou[j]++;
                if (in[i] == 0)
                    b--;
                in[i]++;
            }
        }
    }

    std::cout << a << " ";
    for (int i = 0; i < n; i++)
        if (ou[i] == 0)
            std::cout << i + 1 << " ";
    std::cout << std:: endl;

    std::cout << b << " ";
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            std::cout << i + 1 << " ";
    std::cout << std:: endl;

    fclose(stdout);
    return 0;
}