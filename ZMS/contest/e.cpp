#include <iostream>
#include <vector>
#include <algorithm>

bool comp(long long a, long long b) {
    return a > b;
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<int> v;
    v.reserve(n);
    for (long long i = 0; i < n; ++i) {
        long long t;
        std::cin >> t;
        v.push_back(t);
    }

    std::stable_sort(v.begin(), v.end(), comp);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += std::max(v[i] - i, 0);
    }
    std::cout << ans << std::endl;

    return 0;
}