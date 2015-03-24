#include <iostream>
using namespace std;
double f [1001][1001];//n*m;
int tf[1001][1001];
double m(double a, double c)
{
    if (a < c)
        return a;
    return c;
}
double min(int i, int j)
{
    if (i + j == 0)
        return 0;
    double a = 99999999, b = 99999999, c = 99999999;
    if (i > 0)
        a = f[i - 1][j] + 100;
    if (j > 0)
        b = f[i][j - 1] + 100;
    if (tf[i][j] == 1)
        c = f[i - 1][j - 1] + 100 * 1.4142135623730951;
    return m(a, m(b, c));
}
int main()
{
    int n, m;
    cin >> n >> m;
    n++;
    m++;
    int k;
    cin >> k;
    for (int a, b, i = 0; i < k; i++) {
        cin >> a >> b;
        tf[a][b] = 1;
    }
    for (int i = 1; i < n ; i++)
        f[i][0] = f[i - 1][0] + 100;
    for (int i = 1; i < m; i++)
        f[0][i] = f[0][i - 1] + 100;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            f[i][j] = min(i, j);
        }

    /* for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++)
             cout << f[i][j]  << " ";
         cout << endl;
     }*/
    int ans = f[n - 1][m - 1] * 10;
    if (ans % 10 > 4)
        ans = ans / 10 + 1;
    else
        ans /= 10;
    cout << ans << endl;

    return 0;
}