#include <iostream>
double k;
using namespace std;
void go(double n, double m, double dm)
{
    cout << "power in wt = " << (n * 735.5) << endl;
    cout << "max speed in km/h= " << ((n * 735.5) / (4 * m) * 3.6) << endl;
    cout << "max speed with you in km/h= " << ((n * 735.5) / (4 * (m + dm)) * 3.6) << endl << endl;
}

int main()
{
    cout << "friction coefficient = ";
    cin >>  k;
    cout << "good, k = " << k << endl;

    double  n = 1, m = 1, dm;
    while (n + m != 0) {
        cout << "please input:\n" << "power in h.s = ";
        cin >> n;
        cout << "vehicle weight in kg = ";
        cin >> m;
        cout  << "your weight in kg = ";
        cin >> dm;
        cout << endl;
        go(n, m, dm);
    }
    return 0;
}
