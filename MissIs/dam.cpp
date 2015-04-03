#include <iostream>
#include <vector>
#include <algorithm>

typedef long long LL;
#define puba push_back
const int mod = 1e9 + 7;
LL p[8][8];
int main() {

    for (int i = 0; i < 8; ++i) {
        p[0][i] = 1;
    }
    //p[1][0] = 1;
    //p[1][7] = 1;

    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (j == 0) {
                p[i][j] = p[i - 1][j + 1];
                continue;
            }
            if (j == 7) {
                p[i][j] = p[i - 1][j - 1];
                continue;
            }
            p[i][j] = p[i - 1][j + 1] + p[i - 1][j - 1];
        }
    }
    int x, y;
    std::cin >> x >> y;
    --x, --y;
    std::cout << p[7 - y][x] << "\n";

    return 0;
}