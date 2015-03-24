#include <iostream>
#include <cstdio>
#include <vector>

#define INF 1000ll*1000*1000*1000

#define pb(i) push_back(i)

struct Vertex
{
    long long a;
    long long c;
};

void dijkstra(std::vector < std::vector < Vertex > > g, long long s, long long f) {
    long long n = g.size();

    std::vector<long long> dist(n, INF);
    std::vector<long long> p(n, 0);
    dist[s] = 0;
    p[s] = s;

    std::vector<bool> used(n, 0);

    while (true) {
        long long v = -1;

        for (long long i = 0; i < n; ++i) {
            if (!used[i] && (v == -1 || dist[i] < dist[v])) {
                v = i;
            }
        }

        if (v == -1)
            break;

        for (long long i = 0; i < g[v].size(); ++i) {
            if (dist[v] + g[v][i].c < dist[g[v][i].a]) {
                dist[g[v][i].a] = dist[v] + g[v][i].c;
                p[g[v][i].a] = v;
            }
        }
        used[v] = 1;
    }

    std::cout << dist[f] << std::endl;


    long long t = f;
    std::cout << f + 1 << " ";
    while (p[t] != s) {
        t = p[t];
        std::cout << t + 1 << " ";
    }
    std::cout << s + 1 << std::endl;

    return;
}

int main() {
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);

    long long n, m;
    std::cin >> n >> m;
    long long s, f, w = INF;
    std::cin >> f >> s;
    s--;
    f--;

    std::vector < std::vector < Vertex > > v;
    v.resize(n);

    Vertex ver;
    for (long long i = 0, a, b, c; i < m; ++i) {
        std::cin >> a >> b >> c;
        a--;
        b--;
        ver.a = a;
        ver.c = c;
        v[b].pb(ver);
        ver.a = b;
        v[a].pb(ver);
    }
    dijkstra(v, s, f);

    fclose(stdout);
    return 0;
}