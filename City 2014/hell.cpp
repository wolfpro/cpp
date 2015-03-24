#include <iostream>

int main() {

    int a, b, n;
    std::cin >> a >> b >> n;
    int l, r;
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        r = l + 1;
        while (r < n) {
            if ((l / a == r / a) && (r / b != l / b)) {
                ++ans;
                // std::cout << l << " " << r << '\n';
            }
            ++r;
        }
    }

    std::cout << ans << "\n";

    return 0;
}