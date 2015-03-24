#include <iostream>
#include <vector>

int main() {
    long long v, e;
    std::cin >> v >> e;

    std::vector<long long> p(v);
    for (long long i = 0; i < v; ++i) {
        std::cin >> p[i];
    }

    std::vector < std::vector<long long> > pn(v);
    std::vector < std::vector<long long> > g(v);

    for (long long f = 0; f < e; ++f) {
        long long a, b;
        std::cin >> a >> b;
        --a, --b;

        g[a].push_back(b);
        g[b].push_back(a);


        for (long long i = 0; i < 4; ++i) {
            if (i >= pn[a].size()) {
                pn[a].push_back(b);
                break;
            }
            if (pn[a][i] == b)
                break;
        }
        if (pn[a].size() == 4) {
            for (int i = 3; i >= 0; --i) {
                if (pn[a][i] < b) {
                    pn[a][i] = b;
                    pn[a].resize(3);
                    break;
                }
            }
        }
        long long t = a;
        a = b, b = t;

        for (long long i = 0; i < 4; ++i) {
            if (i >= pn[a].size()) {
                pn[a].push_back(b);
                break;
            }
            if (pn[a][i] == b)
                break;
        }
        if (pn[a].size() == 4) {
            for (int i = 3; i >= 0; --i) {
                if (pn[a][i] < b) {
                    pn[a][i] = b;
                    pn[a].resize(3);
                    break;
                }
            }
        }
        //std::swap(a, b);
        //std::cout << "scans:OK\n";
    }

    /*    for (int i = 0; i < pn.size(); ++i) {
            for (int j = 0; j < pn[i].size(); ++j)
                std::cout << pn[i][j] << " ";
            std::cout << '\n';
        }*/


    long long ans = 0, a = 0, b = 0, c = 0, d = 0, n;

    for (long long i = 0; i < v; ++i) {
        long long ta = p[i], tn = 1;

        if (ta > ans) {
            n = tn;
            a = i;
        }

        for (long long j = 0; j < g[i].size(); ++j) {
            ta = 0;
            if (i != g[i][j])
                ta = p[i] + p[g[i][j]];
            tn = 2;

            if (ta > ans) {
                ans = ta;
                n = tn;
                a = i;
                b = g[i][j];
            }

            for (long long t = 0; t < pn[i].size(); ++t) {
                ta = 0;
                //std::cout << "1: " << pn[i][t] << " " << i << " " << g[i][j] << "\n";

                if (i != pn[i][t] && g[i][j] != pn[i][t]) {
                    //std::cout << "2: " << pn[i][t] << " " << i << " " << g[i][j] << "\n";
                    ta = p[i] + p[g[i][j]] + p[pn[i][t]];
                }
                tn = 3;

                if (ta > ans) {
                    ans = ta;
                    n = tn;
                    a = pn[i][t];
                    b = i;
                    c = g[i][j];
                }


                for (long long rt = 0; rt < pn[g[i][j]].size(); ++rt) {
                    ta = 0;
                    tn = 4;
                    //std::cout << pn[g[i][j]].size() << " " << rt << "\n";
                    /*   if (i == 3) {
                           std::cout << "1: " << pn[i][t] << " " << i << " " << g[i][j] << " " << pn[g[i][j]][rt]  << "\n";
                           for (int r = 0; r < pn[0].size(); ++r)
                               std::cout << pn[g[i][j]][r] ;
                           std::cout << n;
                       }*/

                    if ((i != g[i][j]) && (i != pn[i][t]) && (i != pn[g[i][j]][rt]) && (g[i][j] != pn[i][t]) && (g[i][j] != pn[g[i][j]][rt]) && (pn[i][t] != pn[g[i][j]][rt])) {
                        // if (i == 3)
                        //z   std::cout << "2: " << pn[i][t] << " " << i << " " << g[i][j] << " " << pn[g[i][j]][rt]  << "\n";
                        ta = p[pn[i][t]] + p[i] + p[g[i][j]] + p[pn[g[i][j]][rt]];
                    }
                    if (ta > ans) {
                        ans = ta;
                        a = pn[i][t];
                        b = i;
                        c = g[i][j];
                        d = pn[g[i][j]][rt];
                        n = tn;
                    }
                }
            }
        }
    }
    ++a, ++b, ++c, ++d;

    std::cout << ans << "\n"; ё

    if (n == 1)
        std::cout << n << '\n' << a << "\n";
    if (n == 2)
        std::cout << n << '\n' << a << " " << b << "\n";
    if (n == 3)
        std::cout << n << '\n' << a << " " << b << " " << c << " " << "\n";
    if (n == 4)
        std::cout << n << '\n' << a << " " << b << " " << c << " " << d << "\n";

    return 0;
}