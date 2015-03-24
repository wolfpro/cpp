#include <iostream>
#include <cmath>

char str[200];
char ast[200];
int main() {
    setlocale(LC_ALL, "Rus");
    int n = 172;
    char c;
    for (int i = 0; i < n; ++i) {
        std::cin >> c;
        str[i] = c;
    }

    int len = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] != '_')
            ast[len++] = str[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i + 4 <= n) {
            char t[4];
            for (int j = 0; j < 4; j++) {
                t[j] = ast[len + j];
            }
            for (int j = 4; j > 0; --j) {
                ast[i + 4 - j] = t[j - 1];
            }
            i += 4;
            continue;
        }
    }

    int dl = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '_') {
            std::cout << " ";
        }
        std::cout << ast[dl++];
    }
    return 0;
}