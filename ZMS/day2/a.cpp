#include <iostream>
#include <algorithm>
#include <cstdio>

struct Pair {
    long long s; //long
    long long f; //type 0 - start
};

bool comp(Pair a, Pair b) {
    return (a.f < b.f);
}

int main() {
    freopen("request.in", "r", stdin);
    freopen("request.out", "w", stdout);

    long long n;
    std::cin >> n;

    Pair lec[n];

    for (long long i = 0, a, b; i < n; ++i) {
        std::cin >> lec[i].s >> lec[i].f;
    }

    std::stable_sort(lec, lec + n, comp);

    long long ans = 0, l_end = 0;
    for (long long i = 0; i < n; i++) {
        if (lec[i].s >= l_end) {
            ans++;
            l_end = lec[i].f;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}