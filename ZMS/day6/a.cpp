#include <iostream>

long  long f[2][2] = {{1, 0}, {0, 1}}, m[2][2] = {{1, 1}, {1, 0}}, ans_f[2][2] = {{1, 0}, {0, 1}};
long long mod = 1e9 + 7 + 0.5;

void mul(long long ma[2][2]) {
    for (long  long i = 0; i < 2; ++i)
        for (long  long j = 0; j < 2; ++j)
            f[i][j] = ans_f[i][j];

    ans_f[0][0] = (f[0][0] * ma[0][0] + f[0][1] * ma[1][0]) % mod;
    ans_f[0][1] = (f[0][0] * ma[0][1] + f[0][1] * ma[1][1]) % mod;
    ans_f[1][0] = (f[1][0] * ma[0][0] + f[1][1] * ma[1][0]) % mod;
    ans_f[1][1] = (f[1][0] * ma[0][1] + f[1][1] * ma[1][1]) % mod;
}

void multy(long long n) {
    for (int k = 63; k >=  0; --k) {
        mul(f);

        if (((n >> k) & 1) == 1) {
            mul(m);
        }
    }

}

int main() {

    long  long n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    multy(n);

    std::cout << ans_f[0][1] << std::endl;
    return 0;
}