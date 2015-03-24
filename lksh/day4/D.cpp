#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    //  int a = 1, b = 1, c = a + b;
    freopen("ones.in", "r", stdin);
    freopen("ones.out", "w", stdout);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 4 << endl;
        return 0;
    }

    int a = 2, b = 1, c = 1, d;

    for (int i = 2; i < n; i++) {
        d = a + b + c;
        c = b;
        b = a;
        a = d;
    }

    cout  << (a + b + c) << endl;

    fclose(stdout);
    return 0;
}