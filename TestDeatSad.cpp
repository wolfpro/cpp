#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time (NULL));

    int n = rand() % 24;
    if (n < 0)
        n *= -1;
    long long sum = 0;
    //cout << 1;
    long long t;
    long long m[n];
    for (int i = 0; i < n - 1; i++) {
        m[i] = rand() % 100000000 - 50000000;
        sum += m[i];
    }
    sum++;
    cout << n << "  " << sum << endl;

    cout << "1" << endl;
    for (int i = 0; i < n; ++i) {
        cout <<     m[i] << endl;
    }


    cout << "1";
    for (int i = 0; i < n - 1; i++) {
        if (m[i] > 0)
            cout << "+";
        cout << m[i];
    }
    cout << "=" << sum << endl;
    //int k = rand() % 50000000;

    //cout << k << endl;

    return 0;
}