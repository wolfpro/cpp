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
    std::string a, b;
    std::cin >> a >> b;
    // std::cout << a << "\n" << b;

    std::vector< std::vector<int> > v(a.size() + 1);
    for (int i = 0; i <= a.size(); ++i) {
        v[i].resize(b.size() + 1, 0);
        v[i][0] = i;
    }

    for (int i = 0; i <= b.size(); ++i)
        v[0][i] = i;

    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            int t = (a[i - 1] != b[j - 1]);
            //  std::cout << t << "\n";
            v[i][j] = std::min(std::min(v[i][j - 1] + 1, v[i - 1][j] + 1), v[i - 1][j - 1] + t);
        }
    }

    std::cout << v[a.size()][b.size()] << "\n";

    return 0;
}
