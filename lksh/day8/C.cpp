#include <iostream>
#include <cstdio>
#include <algorithm>

void pr(int p[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << p[i] << " ";
    std::cout << std::endl;
}

void prev_per() {
    int n, k;
    std::cin >> n >> k;

    int p[k + 1];
    for (int i = 0; i < k; i++)
        std::cin >> p[i];

    //std::cout << p[k - 1] << " " << k;
    if (p[k - 1] <= n - 1) {
        p[k - 1]++;
        pr(p, k);
        return;
    }

    {
        int i = k - 2;
        while (i > -1 && p[i] + 1 == p[i + 1]) {
            i--;
        }

        if (i == -1) {
            std::cout << "0\n";
            return;
        }

        p[i]++;
        for (i++; i < k; i++) {
            p[i] = p[i - 1] + 1;
        }
        pr(p, k);
        return;
    }
}

int main() {
    freopen("nextcomb.in", "r", stdin);
    freopen("nextcomb.out", "w", stdout);

    prev_per();

    fclose(stdout);
    return 0;
}
