#include <iostream>
#include <cstdio>

int n;
int p[22];
int ans = 0;

bool ch(int k, int t) {
    if (k == 0)
        return 1;

    for (int i = 0; i < k; i++) {
        if (t == p[i] || (k - i == p[i] - t) || (k - i == t - p[i])) {
            //std::cout << k << " " << t << std::endl;
            return false;
        }
    }
    return true;
}

void q(int k) {
    if (k == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (k == 0 || ch(k, i)) {
            p[k] = i;
            q(k + 1);
        }
    }
    return;
}

int main() {
    //freopen("queen2.in", "r", stdin);
    //freopen("queen2.out", "w", stdout);

    std::cin >> n;

    q(0);

    std::cout << ans << std::endl;

    fclose(stdout);
    return 0;
}