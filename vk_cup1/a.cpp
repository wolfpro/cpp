#include <iostream>
#include <vector>
#include <map>

#define puba push_back

std::vector<int> id;
std::map<int, int> name;
std::vector<std::vector<int> > v;


int get_id(int n) {
    int t = name.size();
    auto val = name.find(n);
    if (val != name.end()) {
        return val->second;
    }
    name.emplace(std::make_pair(n, t));

    id[t] = n;
    return t;
}


int main() {

    int m, k;
    std::cin >> m >> k;
    id.resize(m, -1);
    v.resize(m);

    for (int i = 0, a, b; i < m; ++i) {
        std::cin >> a >> b;
        a = get_id(a);
        b = get_id(b);
        v[a].puba(b);
        v[b].puba(a);
    }

    int n = name.size();

    std::vector< std::vector<int> > frend(n);
    for (int i = 0; i < (int)v.size(); ++i)
        frend[i].resize(n);

    for (int i = 0; i < (int)v.size(); ++i) {
        for (int j = 0; j < (int) v[i].size(); ++j) {
            for (int h = 0; h < (int) v[v[i][j]].size(); ++h)
                frend[v[v[i][j]][h]][i]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << id[i] << ": ";
        for (int j = 0; j < n; ++j) {
            if (frend[i][j] < (int)(k * v[i].size() / 100)) {
                std::cout << id[j] << " ";
            }
        }
        std::cout << '\n';
    }

    /* for (int i = 0; i < (int) v.size(); ++i) {
         std::cout << id[i] << ' ';
         for (int j = 0; j < (int) v[i].size(); ++j)
             std::cout << id[v[i][j]] << ' ';
         std::cout << '\n';
     }*/


    return 0;
}