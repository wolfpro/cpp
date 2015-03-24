#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("grig.in", "r", stdin);
    freopen("grig.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int p[n + 1];
    for (int i = 0; i <= n; i++) {
        p[i] = 0;
    }

    p[0] = 1;
    p[1] = 1;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= k; j++) {
            if (i - j > 0)
                p[i] += p[i - j];
        }
    }

    cout << p[n] << endl;

    fclose(stdout);
    return 0;
}