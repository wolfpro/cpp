#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

typedef long long LL;
#define puba push_back
const int mod = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);

    freopen("tickets.in", "r", stdin);
    freopen("tickets.out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i] >> b[i] >> c[i];

    std::vector<int> d(n, 0);
    d[0] = a[0];
    if (n > 0)
        d[1] = std::min(b[0], d[0] + a[1]);
    if (n > 1)
        d[2] = std::min(d[1] + a[2], std::min(c[0], d[0] + b[1]));
    //if (n > 2)
    //  d[3] = std::min(d[2] + a[3], std::min(d[1] + b[2], c[0]));

    for (int i = 3; i < n; ++i) {
        d[i] = std::min(d[i - 1] + a[i], std::min(d[i - 2] + b[i - 1], d[i - 3] + c[i - 2]));
    }

    std::cout << d[n - 1] << "\n";

    fclose(stdout);
    return 0;
}