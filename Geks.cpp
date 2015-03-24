#include <iostream>
using namespace std;

int g[11 * 11][11 * 11];

void add(int a, int b)
{
    g[a][b] = 1;
    g[b][a] = 1;
}

int gn(int p, int l)
{
    int a = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < l + 1; j++)
            a++;

    return a + p;
}

void ch(int n)
{
    int l = -1;
    int p = n;
    for (int i = 0; i < n; l++) {
        i += l;
        p = n - l;
    }

    if (l < 10) {
        if (p < l)
            add(n, n + 1);
        if (p > 0)
            add(n, n - 1);
        if (p < l)
            add(gn(p + 1, l - 1), n);
        if (p > 0)
            add(gn(p, l - 1), n);

        add(gn(p, l + 1), n);
        add(gn(p + 1, l + 1), n);
    }
    if (l == 10) {} //add border left and right;

    /*if (l > 10) {

        add(gn(p, l - 1), n);
        add(gn(p, l - 1), n);
        if (p < l)
            add(n, n + 1);
        if (p > 0)
            add(n, n - 1);

        if (p < l)
            add(gn(p - 1, l + 1), n);
        if (p > 0)
            add(gn(p, l - 1), n);

    }*/

}

int main()
{
    int n = 0;
    for (int i = 0; i < 10l; i++)
        for (int j = 0; j <= i; j++)
            ch(n);

    for (int i = 0; i < 11 * 11; i++) {
        for (int j = 0; j < 11 * 11l; j++)
            cout << g[i][j];
        cout << endl;
    }
    return 0;
}