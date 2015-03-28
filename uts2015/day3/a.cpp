#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>

typedef long long LL;
const double pi = std::acos(-1);

struct Vec {
    LL x, y;
};

struct Lamp {
    LL x, y, p;
};

Vec a, b;

int mult(Vec at, Vec bt) {
    int ans = 0;
    ans = at.x * bt.y - at.y * bt.x;
    // std::cout << ans << " ans\n";
    return ans;
}

bool check(Lamp at, Lamp bt) {
    Vec c = {bt.x - at.x, bt.y - at.y};
    //  std::cout << mult(a, c) << mult(a, b) << mult(b, a) << mult(b, c) << "\n";
    if (mult(a, b) == 0) {
        if (mult(a, c) == 0)
            if ((a.x * c.x + a.y * c.y)  >= 0) {
                return 1;
            }
        return 0;
    } else if (mult(a, c) * mult(a, b) >= 0 && mult(b, a) * mult(b, c) >= 0) {
        return 1;
    }
    return 0;
}

int main() {
    LL n;
    std::cin >> n;
    std::vector<Lamp> v(n);
    for (LL i = 0, x, y; i < n; ++i) {
        if (i == 0) {
            std::cin >> a.x >> a.y >> b.x >> b.y;
        }
        std:: cin >> x >> y;
        v[i].x = x;
        v[i].y  = y;
    }

    for (LL i = 0; i < n; ++i) {
        std::cin >> v[i].p;
    }

    //std::queue <LL> q;
    std::set <LL> q;

    std::vector<bool> bb(n, 1);
    std::vector<LL> ans(n, 0);
    // b[0] = 0;

//    std::queue <LL> n_q;
    std::set <LL> n_q;

    for (int i = 1; i < n; ++i) {
        q.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        if (bb[i] == 1) {
            q.insert(i);
            bb[i] = 0;
            ans[i] = i;
            //std::cout << "er\n";
        }
        // std::cout << q.size() << '\n';

        while (!q.empty()) {
            LL id0 = q.front();
            Lamp t = v[id0];
            q.pop();

            int p = n_q.size();
            for (int j = 0; j < p; ++j) {
                LL id = n_q.front();
                n_q.pop();


                //std::cout << id0 + 1 << ':' << id + 1 << " " << i << '\n' ;
                if (check(t, v[id])) {
                    // std::cout << "ok\n";
                    //std::cout << id0 + 1 << ':' << id + 1 << " " << i << '\n' ;
                    v[id].p--;
                } else {
                    // std::cout << "no\n";
                }

                if (v[id].p <= 0) {
                    // std::cout << id0 + 1 << ':' << id + 1 << " " << i << '\n' ;
                    if (i < id)
                        q.push(id);
                    if (bb[id] == 1) {
                        ans[id] = i;
                        bb[id] = 0;
                    }
                } else
                    n_q.push(id);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] + 1 << ' ';
    }
    std::cout << '\n';
    return 0;
}