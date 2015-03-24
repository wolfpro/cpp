#include <iostream>
#include <cstdio>
#include <string>


int main() {
    std::string s;
    std::cin >> s;
    // scanf("%s", &s);
    int n;
    std::cin >> n;
    int m  = s.size() / n;

    char f[n][m];

    for (int j = 0; j < n; j++)    {
        for (int i = 0; i < m; i++) {
            f[i][j] = s[i + j * m];
            std::cout << f[i][j];
        }
        std::cout << std::endl;
    }



    return 0;
}