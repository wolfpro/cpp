#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

std::string pos[5] = {"C", "R", "U", "L", "D"};

int main() {
    freopen("input.txt", "r", stdin);
    int n = 0;
    std::cin >> n;

    std::string one = "C", two = "C";

    int t, os = 0, ds = 0;
    std::string s;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        for (int j = 0; j < t; ++j) {
            std::cin >> s;

            if (s == two || s == one) {
                continue;
            }

            if (one == "C") {
                one = s;
                os++;
                continue;
            }
            if (two == "C") {
                two = s;
                os++;
                continue;
            }

            if ((s == "U" || s == "D") && (one == "R" || one == "L")) {
                one = s;
                ds++;
                continue;
            }

            if ((s == "U" || s == "D") && (two == "R" || two == "L")) {
                two = s;
                ds++;
                continue;
            }

            if ((s == "R" || s == "L") && (one == "U" || one == "D")) {
                one = s;
                ds++;
                continue;
            }

            if ((s == "R" || s == "L") && (two == "U" || two == "D")) {
                two = s;
                ds++;
                continue;
            }
        }
    }

    double ans = std::sqrt(2);
    ans = ans * ds + os;
    printf("%.10lf\n",  ans);
    return 0;
}