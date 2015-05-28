#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>

typedef long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second
const double Pi = 3.14159265358979323846264338327950288;

int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector < std::vector<int> > v(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(m);
        for (int j = 0; j < m; ++j) {
            char c;
            std::cin >> c;
            v[i][j] = 0;//<
            if (c == '>')
                v[i][j] = 1;
            if (c == 'v')
                v[i][j] = 2;
            if (c == '^')
                v[i][j] = 3;
            if (c == '.')
                v[i][j] = 10;
            // std::cout << v[i][j];
        }
        //std::cout << '\n';
    }


    int ans = 0;
    int i = n - 1, j = 0;
    bool fl = 0;

    while (i > 0 || j < m) {
        // std::cout << i << "\n";
        if (i >= n || i < 0 || j >= m || j < 0)
            break;
        int s = v[i][j];
        if (s == 10)
            fl = 1;
        ++ans;
        if (s == 4)
            break;
        if (i == 0 && j == m - 1)
            break;
        v[i][j] = 4;
        i += dy[s];
        j += dx[s];
    }
    if (!fl)
        ans = 0;
    std::cout << ans - 1 << '\n';
    return 0;
}