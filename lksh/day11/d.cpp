#include <iostream>
#include <vector>
#include <queue>

struct Pair {
    int a, c;
};

int main() {
    //std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector< std::vector<Pair> > v(n);
    int s, t;
    std::cin >> s >> t;
    --s, --t;

    std::vector<int> len(n, -1);

    Pair p;
    for (int i = 0, a, b, c; i < m; ++i) {
        std::cin >> a >> b >> c;
        --a, --b;
        p.a = a;
        p.c = c;
        v[b].push_back(p);
        p.a = b;
        v[a].push_back(p);
    }

    std::queue <Pair> q;
    for (int i = 0; i < (int) v[s].size(); ++i) {
        q.push(v[s][i]);
        len[v[s][i].a] = v[s][i].c;
    }

    while (!q.empty()) {
        p = q.front();
        q.pop();
        for (int i = 0; i < (int)v[p.a].size(); ++i) {
            if (len[v[p.a][i].a] < 0) {
                q.push(v[p.a][i]);
                len[v[p.a][i].a] = len[p.a] + p.c;
            }/* else {
                if (len[v[p.a][i].a] > len[p.a] + p.c) {
                    q.push(v[p.a][i]);
                    len[v[p.a][i].a] = len[p.a] + p.c;
                }
            }*/
        }
        //  std::cout << "OK\n";

    }

    std::cout << len[t] << '\n';
    return 0;
}