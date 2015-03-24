#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

void merge(int a[], int la, int b[], int lb, int c[]) {
    int lc[la + lb];
    for (int i = 0; i < la; i++) {
        lc[i] = a[i];
    }
    for (int i = 0; i < lb; i++) {
        lc[i + la] = b[i];
    }

    for (int i = 0; i < la + lb; ++i)
    {
        c[i] = lc[i];
        cout << c[i] << " ";
    }
    cout << endl;
}

int main () {
    freopen("knights-in-the-row.in", "r", stdin);
    freopen("knights-in-the-row.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    int ans[n + 2];
    int gans[n + 2];
    //list<int> l;

    for (int i = 0; i <= n + 2; i++) {
        ans[i] = 0;
        gans[i] = i;
        //     l.push_back(i);
    }
    int s = n + 1;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;

        int lef = 0, rig = s + 1, m = lef + (rig - lef) / 2;

        while (rig - lef > 1) {
            m = lef + (rig - lef) / 2;
            if (gans[m] < a)
                lef = m;
            else
                rig = m;
        }
        int t = lef;

        while (rig - lef > 1) {
            m = lef + (rig - lef) / 2;
            if (gans[m] > b)
                rig = m;
            else
                lef = m;
        }
        //rig = lef;
        lef = t;
        for (int i = lef; i < rig; i++) {
            if (gans[i] != c) {
                ans[gans[i]] = c;
                //  t++;
            }
        }
        gans[lef + 1] = c;
        merge(gans, lef + 2, gans + b, s - b + 1, gans);
        s =  s - b + a + 1;

    }

    for (int i = 0; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;

    fclose(stdout);
    return 0;
}