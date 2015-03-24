#include <iostream>
#include <vector>
#include <cstdio>

#define pub push_back

long long a = 12345, b = 123;

long long pow(long long x, long long n) {
    for (long long i = 1, m = x; i < n; ++i)
        x *= m;
    return x;
}

int main() {
    freopen("merge.in", "r", stdin);
    freopen("merge.out", "w", stdout);

    long long n;
    std::cin >> n;
    long long one = 0, two = 1;

    long long k1 = 0, k2 = 1;

    ++n;
    while (k1 + k2 <= n) {
        while (two > one) {
            //std::cout << one << ":1 " << k1 + k2 << '\n';
            if (k1 + k2 == n) {
                std::cout << one << '\n';
                return 0;
            }
            one = one + pow(++k1, 2) % b;
        }
        // std::cout << two << ":2 "  << '\n';
        if (k1 + k2 == n) {
            std::cout << two << '\n';
            return 0;
        }
        two = two + pow(++k2, 3) % a;
    }

    /*  std::cout << one << " " << two << '\n';
      for (long long i = 1; i < n; ++i) {
          one = one + pow(i + 1, 2) % a;
          two = two + pow(i + 1, 3) % b;

          std::cout << one << " " << two << '\n';
      }
    */

    fclose(stdout);
    return 0;
}