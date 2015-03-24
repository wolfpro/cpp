#include <iostream>
#include <string>
#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <stack>

int c[5001][5001];
int main() {
    freopen("lcstr.in", "r", stdin);
    freopen("lcstr.out", "w", stdout);

    std::string a, b, s3 = "";

    std::cin >> a >> b;

    // int trtr[5001][5001];


    for (int i = 0; i < a.size() + 1; i++) {
        for (int j = 0; j < b.size() + 1; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
                //    continue;
            } else if (a[i - 1] == b[j - 1]) {
                c[i][j] = 1;
                //continue;
            } else
                c[i][j] = 0;
            //  std::cout << c[i][j];
        }
        // std::cout << std::endl;
    }

    int ai, aj, l = 0;

    for (int i = 0; i < a.size() + 1; i++)
        for (int j = 0; j < b.size() + 1; j++)
            if (c[i][j] == 1) {
                int tai = i, taj = j, tl = 0;
                while (c[tai][taj] == 1 && tai < a.size() + 1 && taj < b.size() + 1) {
                    tl++;
                    taj++;
                    tai++;
                    //  std::cout << tl << " " << l << "\n";
                }
                if (tl > l) {
                    l = tl;
                    ai = i;
                    aj = j;
                }
            }

    // std::cout << l;
    for (int i = 0; i < l; i++) {
        std::cout << a[ai - 1];
        ai++;
    }

    std::cout << std::endl;


    fclose(stdout);
    return 0;
}