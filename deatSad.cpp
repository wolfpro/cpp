#include <iostream>
using namespace std;
int sig[25];
int pow(int n)
{
    int a = (1 << n) - 1 ;
    //for (int i = 0; i < n; i++)

    return a;
}

/*bool sum(int *m, int n, int index, long long s)
{
    int sign[n];
    sign[0] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (index && 1)
            sign[i + 1] = 1;
        else
            sign[i + 1] = -1;
        index = index >> 1;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += m[i] * sign[i];

    return (s == sum);
}*/
long long sum(int *m, int n, int index, long long s)
{
    int sign[n];
    sign[0] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (index && 1)
            sign[i + 1] = 1;
        else
            sign[i + 1] = -1;
        index = index >> 1;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += m[i] * sign[i];

    return (s == sum);
}

void prin(int *m, int n, int index, long long s)
{
    int sign[n];
    sign[0] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (index && 1)
            sign[i + 1] = 1;
        else
            sign[i + 1] = -1;
        index = index >> 1;
    }
    cout << m[0];

    for (int i = 1; i < n; i++) {
        if (sign[i] == 1)
            cout << "+";

        cout << m[i];
    }
}

int main()
{
    int n;
    long long s;
    cin >> n >> s;

    int m[n];
    for (int i = 0; i < n; i++)
        cin >> m[i];

    int end = pow(n + 1) - 1;
    int start = pow(n);

    long long st = sum(m, n, start, s);

    for (int i = start + 1; i < endl; i++) {
        t=i^(i-1)
    }

    /*for (int i = 0; i < end; i++) {
        if (sum(m, n, i, s)) {
            prin(m, n, i, s);
            cout << "=" << s << endl;
            return 0;
        }
    }*/
    cout << 0;
    cout  << endl;

    return 0;
}