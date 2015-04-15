#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>

typedef long long LL;

#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second

const double Pi = 3.14159265358979323846264338327950288;

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::vector < std::vector <std::string> > v(s.size() + 1);
    for (int i = 0; i < s.size() + 1; ++i) {
        v[i].resize(t.size() + 1);
    }

    v[0][0] = "";

    for (int i = 1; i < s.size(); ++i) {
        v[i][0] = v[i - 1][0];
        v[i][0].puba(s[i]);
    }

    for (int i = 1; i < t.size(); ++i) {
        v[0][i] = v[0][i - 1];
        v[0][i].puba(t[i]);
    }

    for (int i = 1; i < s.size() + 1; ++i)
        for (int j = 1; j < t.size() + 1; ++j) {
            ;//if ()
        }

    return 0;
}