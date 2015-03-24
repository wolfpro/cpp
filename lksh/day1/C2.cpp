#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("diplomas.in", "r", stdin);
    freopen("diplomas.out", "w", stdout);

    long long w, h, n;
    cin >> w >> h >> n;

    long long r = (long long)1000 * 1000 * 1000 * 1000 * 1000 * 1000 , l = 0, m = l + (r - l) / 2;
    // cout << r << endl;

    while ((r - l) > 1) {
        m = l + (r - l) / 2;
        if ((double)n / (m / h) <= (double)(m / w)) {
            r = m;
        } else
            l = m;
        //  cout << l << " " << m << " " << r << endl;
    }

    cout << r << endl;

    fclose(stdout);
    return 0;
}