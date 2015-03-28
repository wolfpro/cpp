#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cassert>

#define FF first
#define SS second
const int inf = 2e9;

struct Pair {
    int b, w;
};

int main() {
    freopen("dag-shortpath.in", "r", stdin);
    freopen("dag-shortpath.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);

    int n, m;
    int s, t;
    std::cin >> n >> m >> s >> t;
    --s, --t;
    std::vector < std::vector < Pair > > v(n);

    for (int i = 0, a, b, c; i < m; ++i) {
        std::cin >> a >> b >> c;
        --a, --b;
        Pair tp = {b, c};
        v[a].push_back(tp);
    }

    std::vector<int> ans(n, inf);

    std::priority_queue <std::pair <int, int> > q;
    ans[s] = 0;
    //std::cout << v[s].w;

    q.push(std::make_pair(0, s));


    while (!q.empty()) {
        // std::cout << q.size() << '\n';
        std::pair <int, int> tp = q.top();
        tp.FF = -tp.FF;
        q.pop();

        for (int i = 0; i < v[tp.SS].size(); ++i) {
            if (ans[v[tp.SS][i].b] > ans[tp.SS] + v[tp.SS][i].w) {
                //  std::cout <<  ans[v[tp][i].b]  << " " << ans[tp] + v[tp][i].w << "\n";
                ans[v[tp.SS][i].b] = ans[tp.SS] + v[tp.SS][i].w;
                //q.push(std::make_pair(-v[tp.SS][i].w, v[tp.SS][i].b));
            }
        }
        // std::cout << "dsad";
    }

    //for (int i = 0; i < n; ++i)
    if (ans[t] == inf)
        std::cout << "Unreachable\n";
    else
        std::cout << ans[t] << '\n';
    //std::cout << '\n';

    return 0;
}