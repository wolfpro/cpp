#include <iostream>
#include <algorithm>
#include <vector>

struct Dot {
    long long x;
    long long color;
    long long pos;
    long long val;
};

bool cmp(Dot a, Dot b) {
    if (a.x == b.x)
        return (a.color > b.color);
    return (a.x < b.x);
}
bool cmp2(Dot a, Dot b) {
    return a.pos < b.pos;
}

long long min(long long a, long long b) {
    if (a > b)
        return b;
    return a;
}
long long max(long long a, long long b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    freopen("segments.in", "r", stdin);
    freopen("segments.out", "w", stdout);

    long long n, m;
    std::cin  >> n >> m;
    std::vector<Dot> v(2 * n);

    for (long long i = 0; i < n; ++i) {
        long long a, b;
        std::cin >> a >> b;
        v[i * 2].x = min(a, b);
        v[i * 2 + 1].x = max(a, b);
        v[i * 2].color = 1;
        v[i * 2 + 1].color = -1;
        // v[i].color = 1 - 2 * (i % 2);
    }
    /*for (long long i = 0; i <  (long long) v.size(); ++i)
        std::cout << v[i].color << " ";
    std::cout << '\n';*/

    for (long long i = 0; i < m; ++i) {
        Dot t;
        std::cin >> t.x;
        t.color = 0;
        t.pos = i;
        v.push_back(t);
    }

    std::stable_sort(v.begin(), v.end(), cmp);

    for (long long i = 0, cur = 0; i <  (long long) v.size(); ++i) {
        v[i].val = cur;
        cur += v[i].color;
    }

    std::stable_sort(v.begin(), v.end(), cmp2);

    for (long long i = 0; i <  (long long) v.size(); ++i)
        if (v[i].color == 0)
            std::cout << v[i].val << " ";

    std::cout << "\n";

    fclose(stdout);
    return 0;
}