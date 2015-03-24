#include <iostream>
#include <vector>
#include <cstdio>

int dx[4] = { -1, 1, 2, 2};
int dy[4] = {2, 2, 1, -1};


int MAX = 104;

int n, m;
std::vector< std::vector<unsigned long long > > f;

void add(int i, int j) {
    for (int k = 0; k < 4; ++k) {
        int x =  j + dx[k], y = i + dy[k];
        if (x > -1 && y > -1 && x < MAX && y < MAX) {
            // std::cout << x << " " << y << '\n';
            f[y][x] += f[i][j];
        }
    }
}

int main() {
    freopen("knight2.in", "r", stdin);
    freopen("knight2.out", "w", stdout);

    std::cin >> n >> m;

    f.resize(MAX);
    for (int i = 0; i < MAX; ++i)
        f[i].resize(MAX);

    f[0][0] = 1;

    for (int i = 0; i < MAX; ++i) {
        for (int j = i; j >= 0; --j)
            if (i - j < n && j < m)
                if (f[i - j][j] > 0)
                    add(i - j, j);
    }

    /*    for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10;  ++j)
                std::cout << f[i][j] << '.';
            std::cout << '\n';
        }*/
    std::cout << f[n - 1][m - 1] << '\n';

    fclose(stdout);
    return 0;
}