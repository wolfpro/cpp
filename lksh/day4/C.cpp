#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <climits>

using namespace std;

int f[1002][1002];
int s[1002][1002];
//int p[1002][1002];

int x[2] = {0, 1};
int y[2] = {1, 0};

struct Pair
{
    int x;
    int y;
};

stack <Pair> st;
Pair p;

void path(int a, int b) {
    int one = INT_MAX, two = INT_MAX;

    if (a - 0 >= 0 && b - 1 >= 0)
        one = s[a - 0][b - 1];

    if (a - 1 >= 0 && b - 0 >= 0)
        two = s[a - 1][b - 0];

    if (min(one, two) == INT_MAX) {
        cout << a << " r" << b << endl;
        return;
    } else {
        if (min(one, two) == one) {
            p.x = a - 0;
            p.y = b - 1;
            path(a, b - 1);
        } else {
            p.x = a - 1;
            p.y = b - 0;
            path(a - 1, b);
        }
    }
}

int main () {

    freopen("pdd.in", "r", stdin);
    freopen("pdd.out", "w", stdout);

    int n, m;
    cin >> n;
    m = n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> f[i][j];

    s[0][0] = f[0][0];

    for (int i = 1; i < n; i++)
        s[i][0] = s[i - 1][0] + f[i][0];

    for (int i = 1; i < m; i++)
        s[0][i] = s[0][i - 1] + f[0][i];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            s[i][j] = min(s[i - 1][j], s[i][j - 1]) + f[i][j];
            // cout << s[i][j] << " ";
        }
        //    cout << endl;
    }

    cout << s[n - 1][m - 1] << endl;

    p.x = n - 1;
    p.y = m - 1;
    st.push(p);

    /*{
        int i = n - 1, j = m - 1;

        while (i > 1 || j > 1) {
            if (i - x[0] >= 0 && i - x[1] >= 0 && j - y[0] >= 0 && j - y[1] >= 0) {
                if (min(s[i - x[0]][j - y[0]], s[i - x[1]][j - y[1]]) == s[i - x[0]][j - y[0]]) {
                    p.x = i - x[0];
                    p.y = j - y[0];
                    st.push(p);
                }
                else {
                    p.x = i - x[1];
                    p.y = j - y[1];
                    st.push(p);
                }
            } else {
                if (i - x[0] < 0 || j - y[0] < 0) {
                    p.x = i - x[1];
                    p.y = j - y[1];
                    st.push(p);
                } else {
                    p.x = i - x[0];
                    p.y = j - y[0];
                    st.push(p);
                }

            }
        }
    }*/

    path(n - 1, m - 1);

    p.x = 0;
    p.y = 0;
    st.push(p);
    cout << st.size() << endl;
    while (st.size() > 0) {
        p = st.top();
        cout << p.x + 1 << " " << p.y + 1 << endl;
        st.pop();
    }

    fclose(stdout);
    return 0;
}