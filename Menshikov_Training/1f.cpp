#include <iostream>
#include <algorithm>
#include <vector>

const int MAX = 10e8;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::vector<int> v;
    for (int i = 0; i < 5; ++i) {
        int t;
        std::cin >> t;
        v.push_back(t);
    }
    v.push_back(MAX);
    std::sort(v.begin(), v.end());

    std::vector<int> cool;
    int l = 0, r = 0;
    for (; r < 6; ++r) {
        if (v[l] != v[r]) {
            if (r - l > 1)
                cool.push_back(r - l);
            l = r;
        }
    }
    std::sort(cool.rbegin(), cool.rend());

    if (cool.size() > 0) {
        if (cool[0] == 5) {
            std::cout << "Impossible\n";
            return 0;
        }
        if (cool[0] == 4) {
            std::cout << "Four of a Kind\n";
            return 0;
        }
    }

    if (cool.size() > 1)
        if (cool[0] == 3 && cool[1] == 2) {
            std::cout << "Full House\n";
            return 0;
        }

    bool f = 0;
    for (int i = 1; i < 5; ++i) {
        if (v[i] - 1 != v[i - 1]) {
            f = 1;
        }
    }
    if (!f) {
        std::cout << "Straight\n";
        return 0;
    }

    if (cool.size() > 0 && cool[0] == 3) {
        std::cout << "Three of a Kind\n";
        return 0;
    }
    if (cool.size() > 1 && cool[0] == 2 && cool[1] == 2) {
        std::cout << "Two Pairs\n";
        return 0;
    }

    if (cool.size() > 0 && cool[0] == 2) {
        std::cout << "One Pair\n";
        return 0;
    }
    std::cout << "Nothing\n";
    return 0;
}