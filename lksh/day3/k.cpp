#include <vector>
#include <cstdio>
#include <iostream>
#include <cassert>

struct Node {
    int l, r, x, val;
    bool vis;
    bool live;
};

std::vector<Node> tree;
std::vector<int> ans;

int build(int l, int r) {
    if (l > r)
        return 0;
    int m = (l + r) / 2;
    tree[m].val = m;
    tree[m].x = 0;
    tree[m].vis = 1;
    tree[m].live = 1;

    tree[m].l = build(l, m - 1);
    tree[m].r = build(m + 1, r);
    return m;
}

bool check(int x, int root) {
    int m = tree[root].val;
    if (root == 0)
        return false;

    if (m == x) {
        if (tree[root].vis)
            return true;
        return false;
    }
    if (m > x)
        return check(x, tree[root].l);
    return check(x, tree[root].r);
}

void remove(int l, int r, int x, int root) {
    std::cout << l << ":" << r << ":" << x << ":" << root << "\n";

    if (r < l)
        return;

    int m = tree[root].val;

    if (l <= m && m <= r && tree[root].live) {
        ans[root] = x;
        if (m == x) {
            tree[root].live = 1;
            ans[root] = 0;
        }
    } {
        if (tree[tree[root].l].live)
            remove(l, std::min(m, r), x, tree[root].l);
        if (tree[tree[root].r].live)
            remove(std::max(m, l), r, x, tree[root].r);
        if (!(tree[tree[root].r].live) && !(tree[tree[root].l].live))
            tree[root].live = 0;
    }
}
int main() {
    // std::ios_base::sync_with_stdio(false);

    // freopen("knights-in-the-row.in", "r", stdin);
    //freopen("knights-in-the-row.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    tree.resize(n + 1);
    ans.resize(n + 1);

    int root = build(1, n);

    // remove(5, 10, 2, root);

    for (int i = 0, l, r, x; i < m; ++i) {
        scanf("%d%d%d", &l, &r, &x);
        //  std::cin >> l >> r >> x;
        remove(l, r, x, root);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
        //std::cout << ans[i] << ' ';
    }
    //std::cout << "\n";
    printf("\n");
    fclose(stdout);
    return 0;
}