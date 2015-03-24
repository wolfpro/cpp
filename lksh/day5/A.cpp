#include <iostream>
#include <cstdio>

long long n;
long long ans = 0;

int main() {
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", s tdout);

    std::cin >> n;

    n++;
    long long v[n][10];

    for (int i = 0; i < 10; i++) {
        v[0][i] = 0;
        v[1][i] = 1;
    }
    v[1][0] = 0;

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j > 0 && j < 9)
                v[i][j] = v[i - 1][j] + v[i - 1][j - 1] + v[i - 1][j + 1];
            if (j == 0)
                v[i][0] = v[i - 1][0] + v[i - 1][1];
            if (j == 9)
                v[i][9] = v[i - 1][9] + v[i - 1][8];
        }
    }

    for (int i = 0; i < 10; i++) {
        ans += v[n - 1][i];
    }

    std::cout << ans << std:: endl;

    fclose(stdout);
    return 0;
}
