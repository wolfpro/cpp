#include <iostream>
#include <cstdio>
#include <stack>

struct Pair {
    int x;
    int y;
};

int main() {
    freopen("pdd.in", "r", stdin);
    freopen("pdd.out", "w", stdout);


    int n, m;
    std::cin >> n >> m;

    int v[n][m];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j ++) {
            std::cin >> v[i][j];
        }

    int av[n][m];
    av[0][0] = v[0][0];

    for (int i = 1; i < n; i++)
        av[i][0] = av[i - 1][0] + v[i][0];
    for (int i = 1; i < n; i++)
        av[0][i] = av[i][i - 1] + v[0][i];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            av[i][j] = v[i][j] + std::min(av[i - 1][j], av[i][j - 1]);
        }

    std::stack <Pair> st;
    Pair p;
    {
        int i = n - 1, j = m - 1;
        p.x = i;
        p.y = j;
        while (i > 0 || j > 0) {
            st.push(p);
            if (i > 0 && j > 0) {
                if (std::min(av[i - 1][j], av[i][j - 1]) == av[i - 1][j]) {
                    p.x = --i;
                    p.y = j;
                } else {
                    p.x = i;
                    p.y = --j;
                }
            } else {
                if (i == 0)
                    j--;
                else
                    i--;
            }
        }
    }
    p.x = 0;
    p.y = 0;
    st.push(p);

    std::cout << av[n - 1][m - 1] << std::endl;
    std::cout << st.size() << std::endl;

    while (!st.empty()) {
        p = st.top();
        st.pop();
        std::cout << p.x + 1 << " " << p.y + 1 << std::endl;

    }

    fclose(stdout);
    return 0;
}