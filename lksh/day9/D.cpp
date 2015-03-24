#include <iostream>
#include <vector>
#include <cstdio>

int main() {
    freopen("lights.in", "r", stdin);
    freopen("lights.out", "w", stdout);

    int n, m; //n-vertex, m -edge;
    std::cin >> n >> m;
    std::vector <std::vector<int> > v;

    v.resize(n);
    for (int i = 0, a, b; i < m; i++) {
        std::cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
        // std::cout << "sd" << std::endl;
    }

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i].size() << " ";
    }
    std::cout << std::endl;

    fclose(stdout);
    return 0;
}