#include <iostream>
#include <vector>

const int MAX = -10e8;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p, sm;
    p.reserve(n);
    sm.reserve(n);


    sm.push_back(0);
    p.push_back(0);

    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        if (t > 1) {
            ++sm[sm.size() - 1];
            sm[sm.size() - 1] = i;
        }
        if (t == 0)
            sm[sm.size() - 1] = -MAX;
        if (t < 0) {
            sm.push_back(-t - 1);
            p.push_back(i);
        }
    }

    std::vector<std::Pair> ans;
`

    return 0;
}