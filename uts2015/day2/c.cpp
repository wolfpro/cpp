#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

int check(int a) {
    std::vector<int> v(a + 1, 1);
    for (int i = a; i > 0; --i) {
        if (v[i] == 1) {
            if (i % 2 == 0) {
                v[i / 2] = 0;
            }
            v[i - 1] = 0;
        }
    }

    /*    if (v[0] == 1) {
            for (int i = 0; i < a; ++i) {
                if (v[i])
                    std::cout << i << '.';
            }
            std::cout << a << "\n";
        }*/
    return v[0];

}

int main() {
    //freopen("game.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    // int ttt[10] = {0, 1, 0, 0, 0, 0, 0, 1, 0, 1};

    long long l, r, ans = 0;
    std::cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if (i % 2 == 0 && check(i)) {
            ans += 1;

            int t = i;
            /*    while (t % 2 == 0) {
                    t /= 2;
                }*/
            std::cout << t << '\n';
        }
        //  std::cout << i << '\n';
    }


    std::cout << ans << '\n';
    fclose(stdout);
    return 0;
}