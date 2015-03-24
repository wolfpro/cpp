#include <iostream>
#include <cstdio>

using namespace std;

int x[2] = {2, 1};
int y[2] = {1, 2};
int n, m;

int f[51][51];

int r(int a, int b) {
    if (a == n - 1 && b == m - 1)
        return 1;

    f[a][b] = 1;
    int res = 0;

    int dx = x[0], dy = y[0];
    if (a + dx <= n && b + dy <= m)
        if (f[a + dx][b + dy] == 0)
            res = r(a + dx, b + dy);

    dx = x[1];
    dy = y[1];

    if (a + dx <= n && b + dy <= m)
        if (f[a + dx][b + dy] == 0)
            res += r(a + dx, b + dy);

    f[a][b] = 0;
    return res;
}

int main() {
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);

    cin >> n >> m;

    f[0][0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int dx = x[0];
            int dy = y[0];

            if (i + dx < n && j + dy < m)
                //   if (f[i + dx][j + dy] == 0)
                f[i + dx][j + dy] += f[i][j];

            dx = x[1];
            dy = y[1];

            if (i + dx < n && j + dy < m)
                //  if (f[i + dx][j + dy] == 0)
                f[i + dx][j + dy] += f[i][j];
        }

    cout << f[n - 1][m - 1] << endl;

    //fclose(stdout);
    return 0;
}