#include <iostream>
#include <vector>
#include <cstdio>

typedef long long LL;
typedef long double LD;

int main() {
    LL n, t;
    LD c;
    std::cin >> n >> t >> c;

    std::vector<LL> v(n + 1);
    std::vector<double> mean(n + 1);
    mean[0] = 0.0;

    v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> v[i];
        mean[i] = (mean[i - 1] + v[i] * 1.0 / t) / c;
        v[i] += v[i - 1];
    }

    LL m, dt;
    std::cin >> m;
    double dbd, real;
    for (int i = 0; i < m; ++i) {
        std::cin >> dt;
        real = ((v[dt] - v[dt - t]) * 1.0 / t);
        printf("%0.6f ", real);
        printf("%0.6f ", mean[dt]);
        dbd = (mean[dt] - real) / real;
        if (dbd < 0)
            dbd = -dbd;
        printf("%0.6f\n", dbd);
    }

    std::cout << '\n';
    return 0;
}