#include <iostream>
#include <vector>

std::vector<int> tree;
std::vector<int> val;
const int k = 3;
const int bsb  =  1 << k;
int n;

int build_tree() {
    for (int i = 0; i < n; ++i) {
        tree[i + bsb] = val[i];
    }
    for (int i = bsb - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    return 0;
}

int main() {
    std::cin >> n;
    val.reserve(n);
    tree.resize(2 * bsb);
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        val.push_back(t);
    }

    //make_tree(0, n, 0, 1);
    build_tree();

    for (int i = 1; i < bsb * 2; ++i) {
        std::cout << tree[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}