#include <iostream>
#include <vector>
#include <string>

const unsigned long long MOD = 18446744073709551577;

bool f[151][151];

unsigned long long prep_f[151][151];
unsigned long long prep_f2[151][151];

int n, m;

struct Pair {
    int i, j;

    void cin() {
        std::cin >> i >> j;
        --i, --j;
    }
};

void Prep(Pair p) {
    bool fl = 1;
    for (int i = p.i; i < n; ++i) {
        if (f[i][p.j] == 1)
            fl = 0;
        prep_f[i][p.j] = fl;
    }

    fl = 1;
    for (int j = p.j; j < m; ++j) {
        if (f[p.i][j] == 1)
            fl = 0;
        prep_f[p.i][j] = fl;
    }


    for (int i = p.i + 1; i < n; ++i)
        for (int j = p.j + 1; j < m; ++j) {
            if (f[i][j] == 0)
                prep_f[i][j] = prep_f[i - 1][j] + prep_f[i][j - 1];
        }

    //debug otput
    /*
    std::cout << p.i << '.' << p.j << '\n';
     for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {
             std::cout << prep_f[i][j] << ".";
         }
         std::cout << "end\n";
     }
     */
}

bool go(Pair p, Pair p2) {

    bool fl = 1;
    for (int i = p.i; i < n; ++i) {
        if (f[i][p.j] == 1)
            fl = 0;
        prep_f2[i][p.j] = fl;
    }

    fl = 1;
    for (int j = p.j; j < m; ++j) {
        if (f[p.i][j] == 1)
            fl = 0;
        prep_f2[p.i][j] = fl;
    }

    for (int i = p.i + 1; i < n; ++i)
        for (int j = p.j + 1; j < m; ++j) {
            if (f[i][j] == 0)
                prep_f2[i][j] = prep_f2[i - 1][j] + prep_f2[i][j - 1];
        }

    std::cout << p.i << '.' << p.j << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << prep_f[i][j] << ".";
        }
        std::cout << "end\n";
    }

    if (prep_f[p2.i][p2.j] == prep_f[p.i][p.j] * prep_f2[p2.i][p2.j] && prep_f[p2.i][p2.j] != 0)
        return 0;

    return 1;
}

std::vector<long long> P;

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::string c;
        std::cin >> c;
        for (int j = 0; j < m; ++j) {
            if (c[j] == '#') {
                f[i][j] = 1;
            }
        }
    }

    std::cout << "OK!\n";

    int q;
    std::cin >> q;

    std::vector<Pair> a, b, c;

    for (; q > 0; --q) {
        int A, B, C;

        std::cin >> A;
        a.resize(A);
        for (int i = 0; i < A; ++i) {
            a[i].cin();
        }

        std::cin >> B;
        b.resize(B);
        for (int i = 0; i < B; ++i) {
            b[i].cin();
        }

        std::cin >> C;
        c.resize(C);
        for (int i = 0; i < C; ++i) {
            c[i].cin();
        }

        int cur = 0;

        for (int i = 0; i < A; ++i) {
            Prep(a[i]);

            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) {
                    if (c[k].i >= a[i].i && c[k].j >= a[i].j) {
                        cur += go(b[j], c[k]);
                        if ( go(b[j], c[k]) > 0)
                            std::cout << i << " " << j << " " << k << "\n";
                    }
                }
            }
        }
        std::cout << cur << "\n";
    }

    return 0;
}