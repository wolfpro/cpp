#include <iostream>
#include <cstdio>

int n;
int p[30];
int op = 0, cl = 0;

void pr() {
    for (int i = 0; i < n + n; i++) {
        /* if (p[i] == 0)
             std::cout << "(";
         if (p[i] == 1)
             std::cout << ")";*/
        std::cout << p[i];
    }
    std::cout << std::endl;
    // std::cout << op << " " << cl << " " << n << std::endl;
}

void f(int m, int s) {
    p[s] = m;

    if (s == n + n - 1) {
        pr();
        return;
    }


    if (op < n) {
        op++;
        f(0, s + 1);
        p[s] = m;
        op--;
    }

    if (op - cl > 0) {
        cl++;
        f(1, s + 1);
        p[s] = m;
        cl--;
    }

}

int main() {
    // freopen("brackets.in", "r", stdin);
    // freopen("brackets.out", "w", stdout);

    std::cin >> n;
    op++;
    f(0, 0);
    op--;

    fclose(stdout);
    return 0;
}