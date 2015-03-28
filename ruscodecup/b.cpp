#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
#define puba push_back

std::vector<short> x;
std::vector<short> y;
std::vector<short> z;
std::vector<short> tp;

bool mul(int a, int b, int c) {
    int t = 0;
    while (a > 0) {
        x[t++] = a % 10;
        a / 10;
    }
    t = 0;
    while (b > 0) {
        y[t++] = b % 10;
        b / 10;
    }
    t = 0;
    while (c > 0) {
        z[t++] = c % 10;
        c / 10;
    }
    for (int i = 0; i < 201; ++i) {
        tp[i] = 0;
    }

    for (int i = 0; i < 200; ++i) {
        int per = 0;
        for (int j = 0; j < 200; ++j) {
            tp[]
        }
    }

}

int main() {
    x.resize(101);
    y.resize(101);
    z.resize(201);

    int a, b, c;
    std::cin >> a >> b >> c;
    if (mul(a, b, c)) {
        std::cout << "Infinity\n";
    } else {
        std::cout << "Finity\n";
    }

    return 0;
}