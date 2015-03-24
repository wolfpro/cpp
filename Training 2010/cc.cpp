#include <iostream>

struct Pair
{
    int v;//текущее значение;
    int c;//сколько раньше 1 было;
    /* data */
};

int give(int i) {
    if (i == 0 || i == 1) {
        return 0;
    }
    return 1;
}

int give_perm(int a, int b) {
    if (a == 0) {
        if (b == 0) {
            return 0;
        }
        if (b == 1) {
            return 1;
        }
    }
    if (a == 1) {
        if (b == 0) {
            return 2;
        }
        if (b == 1) {
            return 3;
        }
    }
}

bool fun[4];

Pair din[100 * 1001][4];

int main() {
    /*
    a 0-0
    b 0-1
    c 1-0
    d 1-1
    */
    int n, a, b, c, d;
    std::cin >> n;// >> a >> b >> c >> d;

    for (int i = 0; i < 4; ++i) {
        char c;
        std::cin >> c;
        fun[i] = c - '0';
        if (fun[i] == 1) {
            din[0][i].v = give(i);
            if (i == 1 || i == 3) {
                din[0][i].c = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++i) {
            int val = din[i][j].val;
            for (int f = 0; f < 4; ++f) {
                if (fun[f] = val) {
                    din[i + 1][f].v = give(f);
                    if (f == 1 || f == 3) {
                        din[i][ give_perm()].c = din;
                    }
                }
            }
        }
    }

    return 0;
}