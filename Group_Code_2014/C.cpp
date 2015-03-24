#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

//0 - centr
//1 - up
//2 -  right
//3 - down
//4 - left

int sh(std::string s) {
    if (s == "C")
        return 0;
    if (s == "U")
        return 1;
    if (s == "R")
        return 2;
    if (s == "D")
        return 3;
    if (s == "L")
        return 4;
}


int INF = 282900;

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

double calc(int l, int r, int a, int b) {
    //double sq = std::sqrt(2), ans = 0.0;
    return std::sqrt(std::pow(dx[l] - dx[a], 2) + std::pow(dy[l] - dy[a], 2)) + std::sqrt(std::pow(dx[r] - dx[b], 2) + std::pow(dy[r] - dy[b], 2));
    /*if (l == 0 && a != 0)
        ans ++;
    }
    if (r == 0 &&  b != 0) {
        ans++;
    }

    if (((l == 1 || l == 3) && (a == 2 || a == 4)) || ((l == 2 || l == 4) && (a == 1 || a == 3))) {
        ans += sq;
    }
    if (((r == 1 || r == 3) && (b == 2 || b == 4)) || ((r == 2 || r == 4) && (b == 1 || b == 3))) {
        ans += sq;
    }

    std::cout << ans << std::endl;*/
    // return ans;
}

int main() {
    int n = 0;
    std::cin >> n;

    double sys [n + 1][25]; //[step][condition]
    for (int s = 0; s <= n; ++s)
        for (int l = 0; l < 5; ++l) {
            for (int r = 0; r < 5; ++r) {
                /*   if (l + r == 0)
                       sys[s][l * 5 + r] = 0;
                   else*/
                sys[s][l * 5 + r] = INF;
                //   std::cout << sys[0][l * 5 + r] << " ";
            }
            // std::cout << std::endl;
        }
    sys[0][0] = 0;

    int t = 0, a = 0, b = 0;
    std::string aa = "C", bb = "C";
    for (int i = 0; i < n; ++i) {
        std::cin >> t;

        if (t == 1) {
            std::cin >> aa;
        } else
            std::cin >> aa >> bb;
        a = sh(aa);
        b = sh(bb);

        for (int l = 0; l < 5; ++l) {
            for (int r = 0; r < 5; ++r)
            {
                // one leg
                // l, r -> a, b
                // l,r -> b, a
                // + sys[l, r] || l, a + sys[l, r]
                if (t == 1) {
                    sys[i + 1][a * 5 + r] = std::min(sys[i][l * 5 + r] + calc(l, r, a, r), sys[i + 1][a * 5 + r]);
                    sys[i + 1][l * 5 + a] = std::min(sys[i][l * 5 + r] + calc(l, r, l, a), sys[i + 1][l * 5 + a]);
                } else {
                    sys[i + 1][a * 5 + b] = std::min(sys[i][l * 5 + r] + calc(l, r, a, b), sys[i + 1][a * 5 + b]);
                    sys[i + 1][b * 5 + a] = std::min(sys[i][l * 5 + r] + calc(l, r, b, a), sys[i + 1][b * 5 + a]);
                }

            }

            /* {
            if ( sys[i + 1][a * 5 + b] != INF)
            sys[i + 1][a * 5 + b] = std::min(sys[i][l * 5 + r] + calc(l, r, a, b), sys[i + 1][a * 5 + b]);
            //std::swap(a, b);
            // sys[i][b * 5 + a] = std::min(sys[i][l * 5 + r] + calc(l, r, a, b), sys[i][a * 5 + b]);
            std::cout << sys[i + 1][a * 5 + b]  << " " ;
            }
            std::cout << std::endl;*/
        }
        /* for (int l = 0; l < 5; ++l) {
             for (int r = 0; r < 5; ++r)
                 std::cout << sys[i + 1][l * 5 + r] << " ";
             std::cout << std::endl;
         }*/
    }
    double ans = INF;
    for (int l = 0; l < 5; ++l) {
        for (int r = 0; r < 5; ++r)
            if (ans > sys[n][l * 5 + r])
                ans = sys[n][l * 5 + r];
        // std::cout << std::min(sys[n][l * 5 + r],  sys[n][l * 5 + r]) << std::endl;
    }
    printf("%.10lf\n", ans);
    //std::cout << ans << std::endl;
    return 0;
}
