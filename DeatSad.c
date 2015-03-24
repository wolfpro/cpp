#include <iostream>
using namespace std;
long long pow(long long n)
{
    long long a = 1;
    for (int i = 1; i <= n; i++, a *= 2);
    return a;
}
long long sum(long long *m, long long n, long long i)
{
    long long a = 0;
    for (int j = n; j > 0; j--) {
        if (i % 2 == 0)
            a += m[j] ;
        else
            a -= m[j];
        //   cout << "j=" << j << " m=" << m[j - 1] << endl;
        i /= 2;
    }
    //cout << a << endl;
    return a;
}

void prin(long long *m, long long n, long long i)
{
    bool s[n];
    long long a = 0;
    for (int j = n; j > 0; j--) {
        s[j - 1] = i % 2;
        if (i % 2 == 0)
            a += m[j] ;
        else
            a -= m[j];
        i /= 2;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] || i != 0)
            if (s[i])
                cout << "-";
            else
                cout << "+";

        cout << m[i + 1];
    }
    cout << "=" << a << endl;
}

int main()
{
    long long n, s;
    cin >> n >> s;
    long long m[n];
    for (int i = 0; i < n; i++, cin >> m[i]);

    long long k = pow(n + 1) - 1, p = pow(n), l = sum(m, n, 0);

    if (s > l || sum(m, n, k) > s) {
        cout << "No solution" << endl;
        return 0;
    }

    for (long long i = 0; i <= k; i++) {
        if (sum(m, n, i) == s) {
            prin(m, n, i);
            return 0;
        }
    }

    cout << "No solution" << endl;
    return 0;
}