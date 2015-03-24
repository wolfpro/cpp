#include <iostream>
#include <cstdio>

int main()
{
    /*long long a = (long long) 1000 * 1000 * 1000 * 1000 * 100;
    std::cout << a << std::endl;*/
    long long n, m;
    std::cin >> n >> m;

    long long sum = 0, t;
    for (long long i = 0; i < m; ++i) {
        std::cin >> t;
        sum += t;
    }

    //std::cout << sum << std::endl;
    if (sum % n == 0) {
        std::cout << sum / n << std::endl;
    } else {
        std::cout << (sum / n + 1) << std::endl;
    }

    return 0;
}