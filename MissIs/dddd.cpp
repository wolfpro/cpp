#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

typedef long long LL;
#define puba push_back
const int mod = 1e9 + 7;

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<LL> > v(n);
    std::vector<std::vector<LL> > p(n);
    for (int i = 0; i < n; ++i) {
        v[i].resize(m);
        p[i].resize(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> v[i][j];
        }
    }
    p[0][0] = v[0][0];
    for (int i = 1; i < n; ++i)
        p[i][0] += p[i - 1][0] + v[i][0];

    for (int i = 1; i < m; ++i)
        p[0][i] += p[0][i - 1] + v[0][i];

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            p[i][j] = std::max(p[i - 1][j], p[i][j - 1]) + v[i][j];

    /*    for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << p[i][j] << ".";
            }
            std::cout << "\n";
        }*/
    /*    for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                std::cout << p[i][j] << ".";
            std::cout << "\n";
        }*/
    std::stack <int> st;
    int x = n - 1, y = m - 1;
    while (x >= 0 && y >= 0 && !(x == 0 && y == 0)) {
        if (x == 0) {
            --y;
            st.push(1);
            continue;
        }
        if (y == 0) {
            --x;
            st.push(0);
            continue;
        }
        if (p[x - 1][y] > p[x][y - 1]) {
            --x;
            st.push(0);
        } else {
            --y;
            st.push(1);
        }
    }

    std::cout << p[n - 1][m - 1] << "\n";
    while (!st.empty()) {
        if (st.top() == 1) {
            std::cout << "R ";
        } else {
            std::cout << "D ";
        }
        st.pop();
    }
    std::cout << "\n";

    return 0;
}