#include <iostream>
#include <vector>

typedef long long LL;
#define puba push_back

int main() {
    int n;
    std::cin >> n;
    std::vector < std::vector<LL> > v(n);
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        std::cout << "1\n";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        v[i].puba(1);
    v[1].puba(1);
    std::cout << "1\n1 1\n";
    if (n > 2) {
        std::cout << "1 ";
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j < i; ++j) {
            v[i].puba(v[i - 1][j] + v[i - 1][j - 1]);
            std::cout << v[i][j] << " ";
        }
        v[i].puba(1);
        std::cout << "1 \n";
        if (i + 1 < n)
            std::cout << "1 ";
    }



    return 0;
}