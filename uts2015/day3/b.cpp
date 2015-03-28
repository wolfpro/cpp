#include <iostream>
#include <cmath>

bool in(int a, int b, int c) {
    if (c == 0)
        return 0;
//   int l = a, r = b + 1, m;
    int t = b / c;
    if (c * t >= a)
        return 1;
    return 0;
}

void check(int a, int b, int c, int d) {
    int t = std::min(a, c);
    c = std::max(a, c);
    a = t;
    t = std::min(b, d);
    d = std::max(b, d);
    b = t;

    if (b >= c) {
        std::cout << b << '\n';
        return;
    }

    /*   for (int i = std::min(b, (d - a)); i >= 1; --i) {
           if (in(a, b, i) && in(c, d, i)) {
               std::cout << i << '\n';
               return;
           }
       }*/

    for (int m = b; m > 1 ;) {
        int k = d / m;
        int h = (k + 1) * m;
        if (h - k <= d && h - k >= c) {
            if (in(a, b, m + 1) && in(c, d, m + 1)) {
                std::cout << m << '\n';
                return;
            } else if (in(a, b, m) && in(c, d, m)) {
                std::cout << m << '\n';
                return;
            } else {
                m--;
                std::cout << m << '\n';
                return;
            }
        } else {
            m -= k;
        }
    }

    std::cout << 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int a , b, c, d;
        std::cin >> a >> b >> c >> d;
        check(a, b, c, d);
    }

    return 0;
}