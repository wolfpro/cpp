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

    std::vector<int> v;

    for (LL i = 0, x, a; i < n; ++i) {
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


    return 0;
}