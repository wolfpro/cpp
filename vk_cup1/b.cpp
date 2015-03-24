#include <iostream>
#include <vector>
#include <algorithm>

#define puba push_back

struct Fr {
    int w, h;
};

bool cmp(Fr a, Fr b) {
    return (a.h > b.h || (a.h == b.h && a.w > b.w));
}

int main() {
    /*nt n;
    std::cin >> n;
    std::vector<Fr> v(n);
    int w = 0, h = 0;
    for (int i = 0, a, b; i < n; ++i) {
        std::cin >> a >> b;
        v[i].w = std::max(a, b);
        v[i].h = std::min(a, b);

        w += v[i].w;
        h = std::max(v[i].h, h);
    }

    int s1 = 1000 * 1000 * 1000 + 1000;
    w = 0, h = 0;

    for (int i = 0; i < n; ++i) {
        w = v[i].w;
        h = v[i].h;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (v[j].w <= h && v[j].h < v[j].w) {
                w += v[j].h;
                h = std::max(v[i].w, h);
            } else {
                w += v[j].w;
                h = std::max(v[j].h, h);
            }
        }
        s1 = std::min(h * w, s1);
        w = v[i].h;
        h = v[i].w;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (v[j].w <= h && v[j].h < v[j].w) {
                w += v[j].h;
                h = std::max(v[i].w, h);
            } else {
                w += v[j].w;
                h = std::max(v[j].h, h);
            }
        }
        s1 = std::min(h * w, s1);
    }

    std::cout << s1 << '\n';
    */
    for (int i = 0; i < 1001; ++i) {
        std::cout << "1 1\n";
    }
    return 0;
}