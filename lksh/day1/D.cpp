#include <iostream>
#include <stdio.h>

using namespace std;

//#define FUU a*m*m*m+b*m*m+c*m+d

int main() {
    freopen("cubroot.in", "r", stdin);
    freopen("cubroot.out", "w", stdout);

    double a, b, c, d;

    cin >> a >> b >> c >> d;

    double l = -1e18,  r = 1e18, m = r, k = 1;

    if (a * m * m * m + b * m * m + c * m + d < 0) {
        k = -1;
    }

    while ((r - l) > 0.000001) {
        m = l + (r - l) / 2;

        if (k * (a * m * m * m + b * m * m + c * m + d) > 0) {
            r = m;
        } else
            l = m;
        // cout << a *m *m *m + b *m *m + c *m + d << endl;
    }

    printf("%lf\n",  l);

    fclose(stdout);
    return 0;
}