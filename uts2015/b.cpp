#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>


struct Ivent {
    LL d, t, r, id;
};

bool cmp(Ivent a, Ivent b) {
    return a.t < b.t;
}

LL main() {
    freopen("bestbuy.in", "r", stdin);
    freopen("bestbuy.out", "w", stdout);

    LL c1, c2;
    std::cin >> c1 >> c2;
    LL n;
    std::cin >> n;
    std::vector<Ivent> v(n);
    for (LL i = 0, d, t; i < n; ++i) {
        std::cin >> d >> t;
        v[i].d = d;
        v[i].t = t;
        v[i].r = 0;
        v[i].id = 0;
    }
    LL m;
    std::cin >> m;
    v.resize(n + m);

    std::vector<bool> ban(m + 1, 0);

    for (LL i = 0, l, r; i < m; ++i) {
        std::cin >> l >> r;
        v[n + i].d = 0;
        v[n + i].t = l;
        v[n + i].r = r;
        v[n + i].id = i + 1;
        Ivent t;
        t.t  = r;
        t.r = r;
        t.id = i + 1;
        t.d = 0;
        v.push_back(t);
    }

    std::stable_sort(v.begin(), v.end(), cmp);

    LL ans = 0;
    LL money = 0;
    for (LL i = 0; i < v.size(); ++i) {
        money += v[i].d;
        //   std::cout << money << "$: ";
        /*   if (v[i].d > 0)
               std::cout << '+' << v[i].d << '\n';*/

        if (v[i].id > 0) {
            if (ban[v[i].id] == 0) {
                LL mon = 0;
                if (v[i].t == v[i].r)
                    mon = c2;
                else
                    mon = c1;
                if (mon <= money) {
                    // std::cout << "buy:" << v[i].id << '\n';
                    money -= mon;
                    ban[v[i].id] = 1;
                    ans++;
                }
            }
        }
    }

    std::cout << ans << '\n';
    fclose(stdout);
    return 0;
}