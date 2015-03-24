#include <iostream>

#define W 20
#define H 20

long long s[W][H];

int main() {
    s[0][0] = 1;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (j == 0)
                s[i][j] = 0;
            if (i == j)
                s[i][j] = 1;
            else {
                s[i][j] = j * s[i - 1][j] + s[i - 1][j - 1];
            }
            std::cout << s[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "S(15, 13)=" << s[15][13] << "!\n";
    return 0;
}