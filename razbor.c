#include <iostream>
using namespace std;

int solve(int n, int m, int t, int  c)
{
    int q[n][m] ;
    for (int i = 0; i < n; i++)
        for (int j = 0, p; j < n; j++) {
            cin >> p;
            q[i][j] = p;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0, p; j < n; j++) {
            if (q[i][j] == 1) {
                q[i][j] = t
            }
        }


}
int main()
{
    int T;
    cin >> T;
    for (int i = 0, n, m, t, c; i < T; i++) {
        cin >> n >> m >> t >> c;
        solve(n, m, t, c);
    }


    return 0;
}