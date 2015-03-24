#include <iostream>
#include <algorithm>
#include <cstdio>

int main() {
    freopen("nextperm.in", "r", stdin);
    freopen("nextperm.out", "w", stdout);

    int n;

    std::cin >> n;

    int p[n + 1];

    for (int i = 0; i < n; i++)
        std::cin >> p[i];

    {
        int i, t;
        for (i = n - 2; i > -1 && p[i] > p[i + 1]; i--);

        if (i == -1) {
            std::reverse(p + i + 1, p + n);
            for (int j = 0; j < n; j++)
                std::cout << p[j] << " ";
            std::cout << std::endl;

            return 0;
        }

        int m = p[i + 1], tj = i + 1;

        for (int j = n - 1; j > i; j--) {
            if (p[j] > p[i] && p[j] < m) {
                m = p[j];
                tj = j;
            }
        }

        std::swap(p[i], p[tj]);

        std::reverse(p + i + 1, p + n);
    }

    for (int i = 0; i < n; i++)
        std::cout << p[i] << " ";
    std::cout << std::endl;

    fclose(stdout);
    return 0;
}