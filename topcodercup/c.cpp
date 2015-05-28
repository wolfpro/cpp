#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
#include <queue>

typedef long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second
const double Pi = 3.14159265358979323846264338327950288;

int main() {
    /*  for (char c = '0'; c <= '9'; ++c)
          std::cout << c << '\n';*/
    int n;
    std::string s;
    std::cin >> n;
    std::getline(std::cin, s);
    std::getline(std::cin, s);
    //std::cout << s << "\n";

    bool ss = 0, bs = 0, nu = 0, ts = 1; // smal big symbol, number;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c >= '0' &&  c <= '9')
            nu = 1;
        else if ('a' <= c && c <= 'z')
            ss = 1;
        else if ('A' <= c && c <= 'Z')
            bs = 1;
        else
            ts = 0;
    }
    if ((s.size() >= n) && ss && bs && nu && ts)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    return 0;
}