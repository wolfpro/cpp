#include <iostream>

long long minut[1441];

int main() {

    long long n;
    std::cin >> n;

    long long a, b, c, d;
    for (long long i = 0; i < 1441; ++i)
        minut[i] = 0;

    for (long long i = 0; i < n; ++i) {
        std::cin >> a >> b >> c >> d;
        if (a > c || (a == c && b == d) || (a == c && b > d)) {
            for (long long j = a * 60 + b; j < 24 * 60; ++j)
                minut[j]++;
            for (long long j = 0; j < c * 60 + d; ++j)
                minut[j]++;
        } else {
            for (long long j = a * 60 + b; j < c * 60 + d; ++j) {
                minut[j]++;
            }
        }
    }

    long long ans = 0;
    for (long long i = 0; i < 1441; ++i) {
        if (minut[i] == n)
            ans++;
    }

    std::cout << ans << std::endl;


    return 0;
}