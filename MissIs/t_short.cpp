#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

typedef long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second

const int mod = 1e9;

int main() {
    // freopen("tshirts.in", "r", stdin);
    //freopen("tshirts.out", "w", stdout);

    /*    int n, m;
        std::cin >> n;
        std::vector<int> v1(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> v1[i];
        }
        std::cin >> m;
        std::vector<int> v2(m);
        for (int i = 0; i < m; ++i)    {
            std::cin >> v2[i];
        }*/

    std::string v1, v2;
    std::cin >> v1 >> v2;
    int n = v1.size(), m = v2.size();

    std::vector<std::vector<int> > d(n + 1);

    for (int i = 0; i <= n; ++i) {
        d[i].resize(m + 1, 0);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v1[i - 1] == v2[j - 1]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                //std::cout << i << " " << j << "; \n";
                d[i][j] = std::max(d[i][j - 1], d[i - 1][j]);
            }
            // std::cout << d[i][j] << " ";
        }
        //std::cout << "\n";
    }

    /*   int s = n, r = m;
       std::stack <int> st;
       while (s > 0 && r > 0) {
           if (v1[s - 1] == v2[r - 1]) {
               st.push(v2[r - 1]);
               --s, --r;P
           } else {
               if (d[s][r - 1] > d[s - 1][r])
                   --r;
               else
                   --s;
           }
       }

       while (!st.empty()) {
           std::cout << st.top() << " ";
           st.pop();
       }*/
    std::cout << (d[n][m]) <<  "\n";

    fclose(stdout);
    return 0;
}