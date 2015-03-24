#include <iostream>
#include <cstdio>
#include <vector>

int m[101][101];

int main() {
    freopen("mtoal.in", "r", stdin);
    freopen("mtoal.out", "w", stdout);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> m[i][j];

    std::vector <std::vector<int> > v;

    v.resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (m[i][j] == 1)
                v[i].push_back(j);

    for (int i = 0; i < n; i++) {
        std::cout << v[i].size() << " ";
        if (v[i].size() > 0) {
            for (int j = 0; j < v[i].size(); j++)
                std::cout << v[i][j] + 1 << " ";
        }
        std::cout << std::endl;
    }

    fclose(stdout);
    return 0;
}