#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("mission.in", "r", stdin);
    freopen("mission.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int q[n];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    int s[k];
    for (int i = 0; i < k; i++)
        cin >> s[i];

    for (int i = 0, t = 0; i < k; i++) {
        t = s[i];
        cout  <<  (std::lower_bound(q, q + n, t) - q) << endl;
    }

    fclose(stdout);
    return 0;
}