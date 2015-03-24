#include <iostream>
#include <vector>

int n = 7;
int b_left[7], b_right[7];

int tans = 0;

int r(int a, int b, int m, int size_left) {

    if (size_left == n) {
        return 0;
    }

    int p1, p2, ans = 0;

    if (m == 1) {
        p1 = b_left[a];
        p2 = b_left[b];
        b_left[a] = 0;
        b_left[b] = 0;
        b_right[a] = p1;
        b_right[b] = p2;
        ans += std::max(p1, p2);

        int mans = 1 << 31 - 1;

        for (int i = 0; i < n; ++i) {
            if (b_right[i] > 0) {
                mans = std::min(mans, r(i, -1, 0, size_left + 2));
            }
        }
        if (mans != 1 << 31 - 1)
            ans += mans;

        b_left[a] = p1;
        b_left[b] = p2;
        b_right[a] = 0;
        b_right[b] = 0;
    } else {
        p1 = b_right[a];
        b_right[a] = 0;
        b_left[a] = p1;
        ans += p1;

        int mans = 1 << 31 - 1;
        for (int i = 0; i < n; ++i) {
            for (int g = i + 1; g < n; ++g) {
                if (b_left[i] > 0 && b_left[g] > 0)
                    mans = std::min(mans, r(i, g, 1, size_left - 1));
            }
        }
        if (mans != 1 << 31 - 1)
            ans += mans;

        b_right[a] = p1;
        b_left[a] = 0;
    }

    return ans;
}

int main() {

    std::cin >> n;
    int ans = 1 << 31 - 1;
    if (n == 1) {
        int t;
        std::cin >> t;
        std::cout << t << std::endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> b_left[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int g = i + 1; g < n; ++g)
            ans = std::min(ans, r(i, g, 1, 0));
    }

    std::cout << ans << std::endl;

    return 0;
}