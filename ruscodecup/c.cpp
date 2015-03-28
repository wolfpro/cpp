#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
#define puba push_back
const int mod = 1e9 + 7;

int n;
std::vector<int> v;
int r(int val, int p, int cur1, int cur2) {
    if (p != n && (cur1 >= n || cur2 >= n))
        return 0;
    if (p == n) {
        return 1;
    }

    if (v[p] == 3) {
        return r(1, p + 1, cur1 + 1, cur2) + r(2, p + 1, cur1, cur2 + 1);
    }
    if (v[p] == val) {
        int c1 = 0, c2 = 0;
        if (val == 1)
            c1++;
        else
            c2++;
        return (val, p + 1, cur1 + c1, cur2 + c2);
    }
    return 0;
}
int main() {
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
    std::cout << r(1, 0, 0, 0) + r(2, 0, 0, 0) << "\n";

    return 0;
}