#include <iostream>
#include <cmath>

bool in(int a, int b, int c) {
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

    int ans = 1;

}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int a , b, c, d;
        std::cin >> a >> b >> c >> d;
        check(a, b, c, d);
    }

    return 0;
}