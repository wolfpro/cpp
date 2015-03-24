#include <iostream>
#include <queue>
#include <cstdio>

int x[4] = {2, 2, 1, -1};
int y[4] = { -1, 1, 2, 2};

bool f[51][51];
int pa[51][51];

struct Pair {
    int x;
    int y;
};

long long ans = 0;

int main () {
    //freopen("knight2.in", "r", stdin);
    //freopen("knight2.out", "w", stdout);

    int n, m;
    std::cin >> m >> n;

    std::queue <Pair> q;
    Pair p;

    p.x = 0;
    p.y = 0;

    q.push(p);
    f[0][0] = 1;
    pa[0][0] = 1;

    while (q.size()) {
        p = q.front();

        q.pop();
        if (p.x == n - 1 && p.y == m - 1) {
            ans++;
        } else
            for (int i = 0; i < 4; i++) {
                Pair tp;
                if ((p.x + x[i] > -1 && p.x + x[i] < n) && (p.y + y[i] > -1 && p.y + y[i] < m)) {
                    tp.x = p.x + x[i];
                    tp.y = p.y + y[i];

                    //  if (f[tp.x][tp.y] == 0 || (tp.x == n - 1 && tp.y == m - 1))
                    q.push(tp);
                    f[tp.x][tp.y] = 1;

                    //z  if (tp.x == n - 1 && tp.y == m - 1)
                    //ans++;
                    pa[p.x + x[i]][p.y + y[i]]++;
                }
            }

    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10;  ++j)
            std::cout << pa[i][j] << '.';
        std::cout << '\n';
    }
    std::cout << ans << std::endl;
    fclose(stdout);
    return 0;
}