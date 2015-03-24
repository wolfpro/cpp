#include <iostream>
#include <cstdio>

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);

    long long n;
    std::cin >> n;
    long long v[n];
    long long s[n];

    for (long long i = 0; i < n; i++) {
        std::cin >> v[i];
        s[i] = 0;
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = i - 1; j > -1; j--) {
            if (v[i] % v[j] == 0) {
                if (s[j] > s[i])
                    s[i] = s[j];
            }
        }
        s[i]++;
    }

    long long ans = 0;

    for (long long i = 0; i < n; i++)
        ans = std::max(ans, s[i]);

    std::cout << ans << std::endl;

    fclose(stdout);
    return 0;
}