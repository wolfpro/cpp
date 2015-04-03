#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

typedef long long LL;
#define puba push_back
const int mod = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> v(n + 2);
    v[0] = -mod;

    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
    v[n + 1] = mod;

    std::sort(v.begin(), v.end());

    std::vector<int> d(n + 2, 0);
    d[0] = mod;
    d[1] = mod;
    d[2] = v[2] - v[1];
    /*   for (int i = 0; i < n + 2; ++i) {
           std::cout << d[i] << " ";
       }*/
    for (int i = 3; i < n + 2; ++i) {
        d[i] = std::min(d[i - 2], d[i - 1]) + v[i] - v[i - 1];
        // std::cout << d[i - 2] << " " << d[i - 1] << "\n";
    }

    /*   for (int i = 0; i < n + 2; ++i) {
           std::cout << d[i] << " ";
       }*/
    std::cout << d[n] << "\n";


    return 0;
}