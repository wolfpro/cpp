#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define pub push_back

int main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<int> v;
    v.reserve(n);

    char c;

    for (int i = 0, p = 0; i < n; ++i) {
        std::cin >> c;
        if (c != '-') {
            std::cin >> p;
        } else {
            std::cout << v[0] << "\n";
            v.erase(v.begin());
        }

        if (c == '+') {
            v.pub(p);
        }
        if (c == '*') {
            v.insert(v.begin() + v.size() / 2 + v.size() % 2, p);
        }

    }

    fclose(stdout);
    return 0;
}