#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>

const long long k = 21;
const long long MC = 1 << k;
const long long inf = 1 << 31 - 1;

struct Node {
    long long vis;
    long long val;
};

long long n;

std::vector<Node> tree(2 * MC);
std::vector<long long> ans;

void build_tree() {
    for (long long i = 0; i < MC; ++i) {
        if (i <= n)
            tree[MC + i].val = i + 1 ;
        else
            tree[MC + i].val = 0;
        tree[MC + i].vis = 1;
    }

    for (long long i = MC - 1; i > 0; --i) {
        tree[i].val = 0;
        tree[i].vis = 1;
    }
}

void remove(long long v, long long tl, long long tr, long long l, long long r, long long x) {
    if (l > r)
        return;
    long long m = (tl + tr) / 2;

    if (tl == l && r == tr && v >= MC) {
        // std::cout << v - MC + 1 << ":" << x << '\n';
        if (tree[v].val != x) {
            ans[tree[v].val] = x;
            tree[v].vis = 0;
        }
    }

    if (v < MC) {
        if (tree[v * 2].vis)
            remove(v * 2, tl, m, l, std::min(r, m), x);
        if (tree[v * 2 + 1].vis)
            remove(v * 2 + 1, m + 1, tr, std::max(l, m + 1), r, x);
        if (!tree[v * 2].vis && !tree[v * 2 + 1].vis)
            tree[v].vis = 0;
    }
}

int main() {
    freopen("knights-in-the-row.in", "r", stdin);
    freopen("knights-in-the-row.out", "w", stdout);

    long long m;
    std::cin >> n >> m;

    build_tree();
    ans.resize(n + 1);

    for (long long i = 0, a, b, x; i < m; ++i) {
        std::cin >> a >> b >> x;
        remove(1, 1, MC, a, b, x);
    }

    for (long long i = 1; i <= n; ++i) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';

    fclose(stdout);
    return 0;
}