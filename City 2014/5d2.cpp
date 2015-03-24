#include <iostream>

int main() {

    std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    bool field[n][m];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char t;
            std::cin >> t;
            if (t == 'W')
                field[i][j] = 0;
            else
                field[i][j] = 1;
        }

    int ans = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            char t;
            int ta;
            std::cin >> t;
            if (t == 'W')
                ta = 1;
            else
                ta = 0;
            if (field[i][j] != ta)
                ++ans;
        }
    std::cout << ans << '\n';

    return 0;
}