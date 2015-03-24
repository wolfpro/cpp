#include <cstdio>
#include <iostream>
#include <string>

int main() {
    int n, m, t = 99999999, mt = 0;

    std::string s, ts;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        std::cin >> ts;
        mt = 0;
        for (int j = 0, d; j < m; ++j) {
            std::cin >> d;
            mt += d;
        }
        if (mt < t) {
            s = ts;
            t = mt;
        }
    }
    std::cout << s << std::endl;

    return 0;
}