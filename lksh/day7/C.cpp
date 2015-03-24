#include <iostream>
#include <cstdio>

int p[101];
int n, k;
int cz = 0, co = 0;

void pr() {
    for (int i = 0; i < n; i++)
        std::cout << p[i];
    std::cout << std::endl;
}

void q(int s) {

    if (s == n) {
        pr();
        return;
    }

    if (cz > 0) {
        p[s] = 0;
        cz--;
        q(s + 1);
        cz++;
    }

    if (co > 0) {
        p[s] = 1;
        co--;
        q(s + 1);
        co++;
    }
}

int main() {
    freopen("combnk.in", "r", stdin);
    freopen("combnk.out", "w", stdout);

    std::cin >> n >> k;
    co = k;
    cz = n - k;

    q(0);

    fclose(stdout);
    return 0;
}