#include <iostream>
using namespace std;
void p(int *m, int n)
{
    for (int i = 0; i < n; i++) {
        cout << m[n - 1 - i]  << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int m[n];
    for (int i = 0; i < n; i++)
        m[i] = 0;
    int l = n;

    for (int i = 0; i < l; i++) {
        m[i]++;
        // p(m, l);
    }
    p(m, l);
    while (l > 0) {
        l--;
        m[l - 1]++;
        //  p(m, l);
        if (m[l - 1] >= m[l - 2])
            p(m, l);

        for (int i = l - 2; i > 0; i--) {
            if (m[i] >= m[i + 1] )
                p(m, l);
            m[i + 1]--;
            m[i]++;
        }
    }
    return 0;
}