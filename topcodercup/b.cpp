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

std::string s;

bool check() {
    bool fl = 0, fl2 = 0;

    for (int i = 0; i < 4; ++i) {
        if (s[i] == '0')
            fl = 1;
    }
    for (int i = 0; i < 4; ++i) {
        if (s[s.size() - 1 - i] == '0')
            fl2 = 1;
    }

    if (fl && !fl2) {
        std::string t = s;
        for (int i = 0; i < s.size(); ++i) {
            t[i] = s[s.size() - 1 - i];
        }
        s = t;
    }

    if (fl + fl2 == 1)
        return 1;
    return 0;
}


int main() {

    std::cin >>  s;
    //std::cout << s.size();
    if (s.size() == 80 && check()) {
        std::cout << s << "\n";
    } else {
        for (int i = 0; i < 80; ++i) {
            std::cout << 0;
        }
        std::cout << "\n";
    }


    return 0;
}