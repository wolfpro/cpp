#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define BAD_VALUE__ONE 101
#define BAD_VALUE__TWO 100000000

int d[BAD_VALUE__ONE];

int main() {
    freopen("bfs.in", "r", stdin);
    freopen("bfs.out", "w", stdout);

    int n, f, s;
    std::cin >> n >> s >> f;
    --f;
    --s;

    std::vector < std::vector<int>  > v;
    v.resize(n);

    for (int i = 0, t = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            std::cin >> t;
            if (t == 1) {
                v[i].push_back(j);
            }
        }

    for (int i = 0; i < n; i++)
        d[i] = BAD_VALUE__TWO;

    std::queue <int> q;
    q.push(s);
    d[s] = 0;

    for (int i = 0, t; i < n; i++) {
        t = q.front();
        q.pop();

        for (int j = 0, tt; j < v[t].size(); j++) {
            tt = v[t][j];
            d[tt] = std::min(d[t] + 1, d[tt]);
            if (std::min(d[t] + 1, d[tt]) == d[t] + 1)
                q.push(tt);
        }
    }

    //for (int i = 0; i < n; i++)
    if (d[f] == BAD_VALUE__TWO)
        std::cout << 0 << std::endl;
    else
        std::cout << d[f] << std::endl;

    fclose(stdout);
    return 0;
}