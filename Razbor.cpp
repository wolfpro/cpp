#include <iostream>

using namespace std;

void work()
{
    int n, m, t, c;
    cin >> n >> m >> t >> c;
    int desire[n][m];
    int ans[n + 1][m];
    for ( int i = 0; i < n; i++)
        for (int j = 0; j < m; ++j) {
            cin >> desire[n][m];
            ans[n][j] = 0;
            ans[i][j] = 0;
        }
    for (int j = 0; j < n; j++)
        if (desire[j][0] == 1)
            ans[j][0] = t;
    ans[n][0] = t;

    // int min = 2147483647;

    for (int j = 0, m = 2147483647; j < m; ++j)
        for (int i = 1; i < n; ++i) {
            {
                if (desire[i][j - 1] == 1 && desire[i][j] == 1 && ans[i][j - 1] == ans[n][j - 1])
                    ans[i][j] = t;
                if (desire[i][j] == 1)
                    ans[i][j] = t + c;
                if (ans[i][j] > 0)
                    min(m, ans[i][j]);
            }
            ans[n][j] = m;
        }
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += ans[n][i];
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        work();

    return 0;
}