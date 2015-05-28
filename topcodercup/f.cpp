#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <cassert>

typedef unsigned long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second
const double Pi = 3.14159265358979323846264338327950288;

LL n, p1, p2, h;
std::string s;
std::vector<LL> st(8, 1);

char sym[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};

LL gh(LL t) {
    for (int i = 0; i < n; ++i) {
        s[n - 1 - i] = sym[t % 10];
        t /= 10;
    }

    LL a = 0;
    for (int i = 0; i < n; ++i) {
        a += ((s[i] - 'a') * st[i]) % p2;
        //std::cout <<  ((s[i] - 'a') * st[i]) << ";\n";
    }
    return a;
}

int main() {
    std::cin >> n >> p1 >> p2 >> h;
    for (int i = 1; i < n; ++i) {
        st[i] = (st[i - 1] * p1) % p2;
    }
    LL t = 0, fa = 1;
    for (int i = 0; i < n; ++i) {
        fa *= 10;
        s += ".";
    }

    for (LL i = 0; i < fa; ++i) {
        t = gh(i);
        if (t == h) {
            std::cout << s << "\n";
        }
    }

    return 0;
}