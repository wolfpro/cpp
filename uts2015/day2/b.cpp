#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

typedef long long LL;
typedef long double LD ;

struct En {
    LL x, a;
    LD t;
};

int main() {
    freopen("trap.in", "r", stdin);
    freopen("trap.out", "w", stdout);

    LL n, k;
    std::cin >> n >> k;
    LD v1, v2;

    std::cin >> v1 >> v2;
    LD s;
    LL s0;
    std::cin >> s0;
    s = s0;
    if (v1 >= v2 && s > 0) {
        std::cout << "inf\n";
        return 0;
    }

    std::queue <En> q;

    for (LL i = 0, x, a; i < n && k > 0; ++i) {
        std::cin >> x >> a;
        if (x < s)
            continue;

        LD t = (x - s) / v1;
        s = x;
        if (t) {
            En tEn = {x, a, t * 1.0};
            q.push(tEn);
            // std::cout << x  << " " << a << " " << t << '\n';
            --k;
        }
    }

    LL p = 0;
    LD t = 0;
    while (!q.empty()) {
        En tEn = q.front();
        q.pop();
        LD lt = (tEn.x - p) * 1.0 / v2 + t;
        // std::cout << lt << '\n';
        if (lt <= tEn.t) {
            std::cout << (t * v1 - p) / (v2 - v1) + t << "\n";
            return 0;
        }

        p = tEn.x;
        t = lt;
        t += tEn.a;
        // std::cout << t << ":\n";
    }

    s = t * v1 + s0;
    std::cout << (s - p) * 1.0 / (v2 - v1) + t << "\n";

    return 0;
}