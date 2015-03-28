#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int ans = 0;
    int p = 0;
    int tr = 0;
    int bs = 0;
    for (int i = 0; i < n; ++i) {
        if (p > 0 && v[i] - p >= 2 * s && bs > 0) {
            ans += s * bs + bs - 1;
            bs = 0;
            p = ans;
        }
        if (v[i] > p && tr == 0) {
            p = v[i];
            bs++;
        }

    }
    std::cout << ans << '\n';


    return 0;
}