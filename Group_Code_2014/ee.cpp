#include <iostream>
#include <cstdio>
#include <cassert>

long long n, m, k;
long long min = 0, max = 0;

const int MEM_SIZE = 240 * 1024 * 1024;
size_t NOW_MEM = 0;
char MEM[MEM_SIZE];

inline void *operator new(size_t l) {
    NOW_MEM += l;
    assert(NOW_MEM <= MEM_SIZE);
    return MEM + NOW_MEM - l;
}

inline void operator delete(void *);

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

long long get_ans() {
    long long ans = 0, mans = 0;

    min = std::min(m, n);
    max = std::max(m, n);

    long long i = (min) % k;
    long long j = k - 1;

    if (i < min + 1) {
        ans = ( get_val(i) + get_val((min - i) / k * k + i)) *  ((min - i) / k + 1) / 2;
        i = ((min - i) / k + 1) * k + i;
    }

    ans += (get_val(min) * (( max - i + k) / k));

    i += (( max - i + k) / k) * k;

    if (i < n + m + 1) {
        ans += (get_val(i) + get_val((n + m - i) / k * k + i)) *  ((n + m - i) / k + 1) / 2;
        i = ((n + m - i) / k + 1) * k + i;
    }

    i = j;

    if (i < min + 1) {
        mans = ( get_val(i) + get_val((min - i) / k * k + i)) *  ((min - i) / k + 1) / 2;
        i = ((min - i) / k + 1) * k + i;
    }

    mans += (get_val(min) * ((max - i + k) / k));
    i = (max + 1) / k * k + j;

    if (i < n + m + 1) {
        mans += (get_val(i) + get_val((n + m - i) / k * k + i)) *  ((n + m - i) / k + 1) / 2;
        i = ((n + m - i) / k + 1) * k + i;
    }
    std::cout << min % k + 1 << " " << ans << std::endl;
    std::cout << k << " " << mans << std::endl;
}

long long mmax(long long a, long long b) {
    if (a > b)
        return a;
    return b;
}

void test() {
    for (m = 1; m < 1000; ++m)
        for (n = m; n < 1000; ++n)
            for (k = 1; k < m + n + 1; ++k) {
                long long ans = 0, mans = 0;

                min = std::min(m, n);
                max = std::max(m, n);

                long long i = (min) % k;
                long long j = k - 1;

                int r = 0;
                for (; i < min + 1; i += k) {
                    ans += get_val(i);
                    r++;
                }

                i = (min) % k;

                int e = 0, ans2 = 0;
                if (i < min + 1) {
                    ans2 = ( get_val(i) + get_val((min - i) / k * k + i)) *  ((min - i) / k + 1) / 2;
                    e = (min - i) / k + 1;
                }

                if (r != e) {
                    std::cout << r << " " << e << std::endl;
                    std::cout << m << " " << n << " " << k << std::endl;
                    return;
                }

                if (ans != ans2) {
                    std::cout << ans << " " << ans2 << std::endl;
                    std::cout << m << " " << n << " " << k << std::endl;
                    return;
                }
                if ((m + n + k) % 2000 == 0) {
                    std::cout << m << " " << n << " " << k << " OK!" << std::endl;
                }
            }
}


int main() {
    std::cin >> n >> m >> k;
    min = std::min(m, n);
    max = std::max(m, n);
    // test();
    get_ans();
    return 0;
}