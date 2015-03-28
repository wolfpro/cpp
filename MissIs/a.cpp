#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cassert>

#define FF first
#define SS second

typedef long long LL;

LL p[2][2] = {{0, 1}, {1, 1}};
LL ans[2][2] = {{0, 1}, {1, 1}};

/*void mul() {
    LL a = ans[0][0], b = ans[0][1], c = ans[1][0], d = ans[1][1] ;
    ans[0][0] = a * p[0][0] % 10 + b * p[1][0] % 10;
    ans[0][1] = a * p[0][1] % 10 + b * p[1][1] % 10;
    ans[1][0] = c * p[0][0] % 10 + d * p[1][0] % 10;
    ans[1][1] = c * p[0][1] % 10 + d * p[1][1] % 10;
    // std::cout << ans[0][0] << '.' << ans[0][1] << "\n";
    //std::cout << ans[1][0] << '.' << ans[1][1] << "\n\n";
}*/

int main() {
    LL n;
    std::cin >> n;
    //  pow(n + 1);
    // std::cout << ans[0][0] % 10 << '\n';
    std::vector<LL> v(3001, 1);
    for (int i = 2; i <= 1000; i += 1) {
        v[2 * i] = v[i] + 1;
        i--;
        v[2 * i + 1] = v[2 * i + 2] + v[i];
        i++;
    }
    std::cout << v[n] % 1000 << '\n';

    return 0;
}