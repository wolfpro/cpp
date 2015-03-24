#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

int main() {
    freopen("colors.in", "r", stdin);
    freopen("colors.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n);
    std::vector<int>::iterator last;

    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    std::sort(v.begin(), v.end());

    std::queue <int> q;

    for (int i = 0, t = 0; i < n && t < k; ++i) {
        std::cout << v[i] << ' ';
        t++;

        while (v[i] == v[i + 1]) {
            q.push(v[i]);
            ++i;

        }

        if (i == n - 1 && t < k) {
            while (t < k) {
                int p = q.front();
                q.pop();
                std::cout << p << ' ';
                ++t;
            }
        }
    }

    std::cout << '\n';
    fclose(stdout);
    return 0;
}