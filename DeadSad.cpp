#include <iostream>
#include <cstdlib>
using namespace std;
int s[25];//0+, 1-;
long long sum;
long long m[25];
int n;
void dfs(int i, long long su)
{
    if (i == n) {
        if ( su == sum) {
            cout << m[0];
            for (int j = 1; j < n; ++j) {
                if (s[j] == 0)
                    cout << "+";
                else
                    cout << "-";
                cout << m[j];
            }
            cout << "=" << su << endl;
            exit(0);
        }
        return;
    }
    s[i] = 0;
    dfs(i + 1, su + m[i]);
    s[i] = 1;
    dfs(i + 1, su - m[i]);

    return ;
}

int main()
{
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
        cin >> m[i];

    dfs(1, m[0]);
    cout << "No solution\n";
    return 0;
}