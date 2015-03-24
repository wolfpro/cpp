#include <iostream>
#include <cstdio>

long long t[25];
long long n;
long long s;
bool out = false;

void r(long long pos, long long sum)
{
    pos++;

    if (out) {
        return;
    }

    if (pos == n) {

        long long ts = 0;
        for (long long i = 0; i < n; ++i)
            ts += t[i];

        if (ts == s) {
            out = true;
            for (long long i = 0; i < n; ++i) {
                if (i > 0 && t[i] > 0)
                    std::cout << "+";
                std::cout << t[i];
            }

            std::cout << "=" << s << std::endl;
        }

        return;
    }

    t[pos] = 0 - t[pos];
    r(pos, sum);
    t[pos] = 0 - t[pos];
    r(pos, sum);
}


int Smain()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin >> n >> s;

    for (long long i = 0; i < n; ++i) {
        std::cin >> t[i];
    }

    r(0, s);

    if (!out) {
        std::cout << "No solution\n";
    }

    return 0;
}