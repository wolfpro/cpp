#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> m >> n;

    std::vector < std::vector<char> > v;

    v.resize(n * 2);

    for (int i = 0; i < 2 * n; i += 2) {
        v[i].resize(2 * m);
        v[i + 1].resize(2 * m);
        //  std::cout << v[i].size() << " \n";
        char c;
        for (int j = 0; j <  2 * m; j += 2) {
            std::cin >> c;
            // std::cout << i <<  " " << j;
            v[i][j] = c;
            v[i][j + 1] = c;
        }
        for (int j = 0; j < 2 * m; ++j)
            v[i + 1][j] = v[i][j];
    }

    for (int j = 1; j <= 2 * m; ++j) {
        for (int i = 1; i <= 2 * n; ++i) {
            std::cout << v[i - 1][j - 1];
        }
        std::cout << '\n';
    }


    return 0;
}