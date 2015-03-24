#include <iostream>
#include <cstdio>
int a[44];
void pr(int k) {
    for (int i = 1; i < k; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
void gen(int n, int k, int i) {
    if (k <= 0)
        return;
    if (n <= 0) {
        pr(i);
        return;
    }
    if (k != 1)
        gen(n, k - 1, i);
    if (n >= k) {
        a[i] = k;
        gen(n - k, k, i + 1);
    }
}
int main() {
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    int n;
    std::cin >> n;
    a[0] = 1;
    gen(n, n, 1);
    fclose(stdout);
    return 0;
    ;
}
