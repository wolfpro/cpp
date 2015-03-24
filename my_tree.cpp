#include <iostream>
#include <vector>

std::vector<int> tree;
std::vector<int> data;

const int k = 3;
const int MC = 1 << k; // magic const or memory const;
const int inf = (1 << 31) - 1;

int n;

void build_tree() {
    for (int i = 0; i < n; ++i) {
        tree[i + MC] = data[i]; //inicialization a foliage;
    }
    for (int i = MC - 1; i > 0; --i) {
        tree[i] = std::min(tree[i * 2] , tree[i * 2 + 1]); //ini a branch;
    }
}

int get_min(int v, int tl, int tr, int l, int r) {
    std::cout << v << ":" << tl << ":" << tr << ":" << l << ":" << r << '\n';
    if (l > r)
        return inf;
    if (tr == r && tl == l)
        return tree[v];

    int m = (tl + tr) / 2;

    return std::min(get_min(v * 2, tl, m, l, std::min(r, m)), get_min(v * 2 + 1, m + 1, tr, std::max(m + 1, l), r));
}

int main() {
    int m;
    std::cin >> n >> m;
    data.reserve(n + 1);

    tree.resize(2 * MC, inf);

    for (int i = 0, t; i < n; ++i) {
        std::cin >> t;
        data.push_back(t);
    }

    build_tree();

    for (int i = 0, a, b; i < m; ++i) {
        std::cin >> a >> b;
        std::cout << get_min(1, 1, MC, a, b) << '\n';
    }

    for (int i = 1; i < MC * 2; ++i) {
        std::cout << tree[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}