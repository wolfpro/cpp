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

int bp(int pos) {
    int p = pos - 1;
    if (p < 0)
        p = 29999;
    return p;
}

std::vector<char> v(30000);
std::string s;
int pos = 0;
int var = 0;

void r(int pt) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '>') {
            pos++;
            pos %= 30000;
        }
        if (s[i] == '<') {
            pos--;
            pos = std::max(0, pos);
        }
        if (s[i] == '|')
            pos = 0;
        if (s[i] == ',') {
            std::cin >> v[pos];
        }
        if (s[i] == '.')
            std::cout << (int)v[pos];
        if (s[i] == '0')
            v[pos] = 0;
        if (s[i] == '!')
            var = v[pos];
        if (s[i] == '?')
            v[pos] = var;
        if (s[i] == '*') {
            v[pos] = (v[pos] * v[bp(pos)]) % 256;
        }
        if (s[i] == '/') {
            v[pos] = (v[pos] / v[bp(pos)]) % 256;
        }
        if (s[i] == '+') {
            v[pos] = (v[pos] + 1) % 256;
        }
        if (s[i] == '-') {
            v[pos] = std::max(0, v[pos] - 1);
        }
    }

    if (s[i] == '[')
        r([pos]);

    if (s[i] == ']')
        if (pt == -1 || v[pt] == 0)
            return;

    r(pt);
}

int main() {
    std::cin >> s;
    r(-1)

    return 0;
}