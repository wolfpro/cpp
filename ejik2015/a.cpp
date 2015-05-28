#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>

typedef long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second
const double Pi = 3.14159265358979323846264338327950288;

int main() {
    int x, n, m;
    std::cin >> n >> m >> x;
    ++n;
    std::cout << n * m / x + (n * m % x > 0) << '\n';
    return 0;
}