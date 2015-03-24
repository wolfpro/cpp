#include <iostream>
#include <vector>
#include <algorithm>

struct Dot {
    long long x;
    long long y;
    bool used;
};

int main() {
    long long m, n;
    std::cin >> m >> n;

    std::vector<Dot> v;
    v.reserve(n);
    for (long long i = 0; i < n; ++i) {
        Dot a;
        a.used = 0;
        std::cin >> a.x >> a.y;

        for (long long i = 0; i < v.size(); ++i) {
            if ((v[i].x <= a.x && a.x <= v[i].y) || (v[i].x <= a.y && a.y <= v[i].y) || (a.x <= v[i].x && v[i].y <= a.y)) {
                v[i].used = 1;
            }
        }
        v.push_back(a);
    }

    long long ans = 0;
    for (long long i = 0; i < v.size(); ++i) {
        if (!v[i].used)
            ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}