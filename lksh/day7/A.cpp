#include <iostream>
#include <cstdio>

int n;

int p[22];

void pr() {
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
}

void f(int k) {
    if (k == n) {
        pr();
        return;
    }

    p[k] = 0;
    f(k + 1);

    if (p[k - 1] != 1) {
        p[k] = 1;
        f(k + 1);
    }

}


int main() {
    freopen("notwo.in", "r", stdin);
    freopen("notwo.out", "w", stdout);

    std::cin >> n;


    f(1);
    p[0] = 1;
    f(1);

    fclose(stdout);
    return 0;
}