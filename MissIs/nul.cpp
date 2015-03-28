#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cassert>
#include <string>

#define FF first
#define SS second

typedef unsigned long long LL;

//std::vector<bool> v(100, 0);
int n;

struct Num {
    std::string val;
};

int main() {
    std::cin >> n;
    std::vector<LL> v0(n + 1, 0);
    std::vector<LL> v1(n + 1, 0);
    std::vector<LL> v2(n + 1, 0);

    v0[0] = 1;
    v1[0] = 1;
    v2[0] = 1;
    for (int i = 1; i < n; ++i) {
        v0[i] = v0[i - 1] + v1[i - 1] + v2[i - 1];
        v1[i] = v0[i - 1] + v1[i - 1] + v2[i - 1];
        v2[i] = v0[i - 1] + v1[i - 1];
    }

    std::cout << (v0[n - 1] + v1[n - 1] + v2[n - 1]) << "\n";



    return 0;
}