#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;
/*
int  m = 2000001;

int min(int a,  int b) {
    if (a < b)
        return a;
    else
        return b;
}

void merge(int a[], int b[], int la, int lb, int c[]) {
    int i = 0, j = 0;
    int tp1, tp2;
    int b2[lb + la];

    for (int t = 0; t < la + lb; t++) {
        if (i < la)
            tp1 = a[i];
        else
            tp1 = INT_MAX;

        if (j < lb)
            tp2 = b[j];
        else
            tp2 = INT_MAX;

        if (min(tp1, tp2) == tp1) {
            b2[t] = tp1;
            i++;
        } else {
            b2[t] = tp2;
            j++;
        }
    }

    for (int i = 0; i < la + lb; i++) {
        c[i] = b2[i];
    }
}

void mergeSort(int a[], int n) {
    if (n < 2) {
        return;
    }
    mergeSort(a, n / 2);
    mergeSort(a + n / 2, n / 2 + n % 2);
    merge(a, a + n / 2, n / 2, n % 2 + n / 2, a);
}

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> m;

    int a[m];
    int b[m];

    for (int i = 0; i < m; i++)
        cin >> a[i];

    mergeSort(a, m);

    for (int i = 0; i < m; i++) {
        cout << a[i];
        if (i != m - 1)
            cout << " ";
    }

    fclose(stdout);
    return 0;
}*/
int  pr[1002];

int main() {
    freopen("goodsolvers.in", "r", stdin);
    freopen("goodsolvers.out", "w", stdout);

    for (int i = 0; i < 1002; i++)
        pr[i] = -1;

    int n, m;
    cin >> n >> m;
    int t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        pr[t - n + 1000]++;
        // cout << t - n + 1000 << endl;
    }

    for (int i = 1000; i > -1; i--) {
        if (pr[i] != -1)
            for (int j = 0; j <= pr[i]; j++)
                cout << (i - 1000 + n) << " ";
    }

    fclose(stdout);
    return 0;
}