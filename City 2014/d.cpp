#include <iostream>


int main() {
    int m, n;
    std::cin >> m >> n;
    int min = std::min(m, n), max = std::max(m, n);

    int sum_sq = 0;
    for (int i = 0; i < min; ++i)    {
        sum_sq += (m - i) * (n - i);
    }

    int k;
    std::cin >> k;

    int ans = 0, a, b;
    for (int i = 0; i < k; ++i) {
        std::cin >> a >> b;
        if (m * n * k * a * b == 1) {
            std::cout << 0 << "\n";
            return 0;
        }
        /*   //ans += 2 * std::min((m - a), (n - b));
           // ans += 2 * std::min(a, b);
           if (a <= min)
               ans += (min - a) * a;
           else
               ans += (a - min) * a;
           if (b <= min)
               ans += (min - b) * b;
           else
               ans += (b - min) * b;*/
        ans += m - a;
        ans += n - b;
    }

    std::cout << sum_sq - ans << std::endl;

    return 0;
}