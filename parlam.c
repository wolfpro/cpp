#include <iostream>
using namespace std;
int k = 1;
int v[3001], l[3001], r[3001];
int mas[3001];
int build(int i, int j)
{
    if (i > j)
        return 0;
    int z = k++;
    //cout << i << "  " << j << endl;
    v[z] = mas[j];
    int t = i;
    while (mas[t] < mas[j])
        t++;
    l[z] = build(i, t - 1);
    r[z] = build(t, j - 1);

    return z;
}

void print(int u)
{
    if (u == 0)
        return;
    print(r[u]);
    print(l[u]);
    cout << v[u] << " ";

}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    int root = build(0, n - 1);
    //cout << root;
    print(root);

    return 0;
}