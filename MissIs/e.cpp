#include <iostream>
#include <cmath>

long long fmax(long long a, long long b) {
    if (a >= b)
        return a;
    return b;
}
long long fmin(long long a, long long b) {
    if (a <= b)
        return a;
    return b;
}

int main() {

    long long m, n, k;
    std::cin >> n >> m >>  k;

    long long I = 0, II = 0, III = 0;
    long long min = fmin(n, m), max = fmax(n, m);

    long long N = min % k + 1;
    //std::cout << "N=" << N << std::endl;
    I = (min + k);
    I /= k;
    I *= (min + 1 + N);
    I /= 2;
    //  std::cout << (min + 1 + N) * (min + k) << std::endl;
    II = ((max + k) / k - (min + k) / k) * (min + 1);
    //std::cout << I << std::endl;


    long long x = ((max + k) / k);
    x = x * k + N - 1;
    //std::cout << x << std::endl;
    III = (m + n - (x - 1) + (m + n + 1 - (((m + n + k) / k - 1) * k + N - 1))) * ((m + n + k) / k - (max + k) / k);
    III /= 2;
    //std::cout << (m + n + 1 - (((m + n + k) / k - 1) * k + N - 1)) << std::endl;

    long long ans = fmax(I, 0) + fmax(II, 0) + fmax(III, 0);
    std::cout << I << " " << II << " " << III << std::endl;

    std::cout << N << " " << ans << std::endl;

    if ((m + n + 1) / k < 1) {
        std::cout << "1 1\n";
        return 0;
    }
    if (k == 1) {
        std::cout << N << " " << ans << std::endl;
        return 0;
    }
    if (N == 1) {
        std::cout << N + 1 << " " << ans << std::endl;
        return 0;
    }
    std::cout << N - 1 << " " << ans - 1 + (k % 2 == 0) << std::endl;

    return 0;
}