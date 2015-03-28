#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cassert>
#include <string>
#include <stack>

#define FF first
#define SS second

typedef unsigned long long LL;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n + 3);
    v[0] = 0;
    v[1] = 0;
    v[2] = 1;
    v[3] = 1;

    for (int i = 4; i <= n; ++i) {
        if (i % 6 == 0) {
            v[i] = std::min(v[i / 2], std::min(v[i / 3], v[i - 1])) + 1;
        } else {
            if (i % 2 == 0) {
                v[i] = std::min(v[i - 1], v[i / 2]) + 1;
            } else if (i % 3 == 0)
                v[i] = std::min(v[i - 1], v[i / 3]) + 1;
            else
                v[i] = v[i - 1] + 1;
        }
    }

    std::stack <int> stack;

    for (int i = n; i > 1;) {
        int a = 1e7, b = 1e7;
        if (i % 2 == 0)
            a = v[i / 2];
        if (i % 3 == 0)
            b = v[i / 3];
        if (v[i] == a + 1) {
            i /= 2;
            stack.push(2);
        } else if (v[i] == b + 1) {
            i /= 3;
            stack.push(3);
        } else {
            i--;
            stack.push(1);
        }
    }

    while (!stack.empty()) {
        std::cout << stack.top();
        stack.pop();
    }

    std::cout << '\n';

    return 0;
}