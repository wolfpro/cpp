#include <iostream>
#include <cstdio>

long long n, m, k;
long long min = 0, max = 0;

long long get_val(long long N) {
    N++;
    if (N < min + 2) {
        return N;
    }
    if (N < max + 2) {
        return min + 1;
    }
    return min + max - N + 2;


}

int main() {
    std::cin >> n >> m >> k;
    long long ans = 0, mans = 0;

    min = std::min(m, n);
    max = std::max(m, n);

    long long i = (min) % k;
    long long j = k - 1;
    for (; (i < n + m + 1) || (j < n + m + 1); i += k, j += k) {
        if (i < n + m + 1)
            ans += get_val(i);
        if (j < n + m + 1)
            mans += get_val(j);
    }

    std::cout << min % k + 1 << " " << ans << std::endl;
    /*ans = 0;

    for (long long i = k - 1; i < n + m + 1; i += k) {
            ans += get_val(i);
            // std::cout << get_val(i) << std::endl;
        }*/
    std::cout << k << " " << mans << std::endl;

    return 0;
}