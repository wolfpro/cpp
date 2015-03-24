#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int  m = 2000001;

int min(int a,  int b) {
    if (a < b)
        return a;
    else
        return b;
}

void merge(int a[], int b[], int la, int lb, int c[], int s1[], int s2[], int c2[], int g1[], int g2[], int c3[]) {
    int i = 0, j = 0;
    int tp1, tp2;
    int ttp1, ttp2;
    int rtp1, rtp2;

    int b2[lb + la];
    int b3[lb + la];
    int b4[lb + la];

    for (int t = 0; t < la + lb; t++) {
        if (i < la) {
            tp1 = a[i];
            ttp1 = s1[i];
            rtp1 = g1[i];
        }
        else
            tp1 = INT_MAX;

        if (j < lb) {
            tp2 = b[j];
            ttp2 = s2[j];
            rtp2 = g2[j];
        }
        else
            tp2 = INT_MAX;

        if (min(tp1, tp2) == tp1) {
            b2[t] = tp1;
            b3[t] = ttp1;
            b4[t] = rtp1;
            i++;
        } else {
            b2[t] = tp2;
            b3[t] = ttp2;
            b4[t] = rtp2;
            j++;
        }
    }

    for (int i = 0; i < la + lb; i++) {
        c[i] = b2[i];
        c2[i] = b3[i];
        c3[i] = b4[i];
    }
}

void mergeSort(int a[], int n, int s[], int gans[]) {
    if (n < 2) {
        return;
    }
    mergeSort(a, n / 2, s, gans);
    mergeSort(a + n / 2, n / 2 + n % 2, s + n / 2, gans + n / 2);
    merge(a, a + n / 2, n / 2, n % 2 + n / 2, a, s, s + n / 2, s, gans, gans + n / 2, gans);
}

int main() {
    freopen("segments.in", "r", stdin);
    freopen("segments.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    int v[n + n + m];
    int gans[m + n + n];
    int ans[m];
    int s[n + n + m];
    int pre = 0;

    for (int i = 0; i < n + n + m; i++) {
        cin >> v[i];

        if (i >= 2 * n) {
            s[i] = 1;
            gans[pre] = i;
            pre++;
        }
        else {
            if (i % 2 == 0)
                s[i] = 0;
            else
                s[i] = 2;
        }
    }

    mergeSort(v, n + n + m, s, gans);

    /*   for (int i = 0; i < n + n + m; i++)
           cout << v[i] << " ";
       cout << endl;
       for (int i = 0; i < n + n + m; i++)
           cout << s[i] << " ";
       cout << endl;*/

    int sum = 0;

    /* for (int i = 0; i < m; i++) {
         cout << gans[i] << " ";
     }
     cout << endl;
    */


    for (int i = 0; i < n + n + m; i++) {
        if (s[i] == 0)
            sum++;
        if (s[i] == 2)
            sum--;
        if (s[i] == 1 ) {
            ans[gans[i]] = sum;
            /* ans[(std::lower_bound(gans, gans + m, v[i]) - gans)] = sum;
             cout << std::lower_bound(gans, gans + m, v[i]) - gans << ":" <<  sum << " " << v[i] << endl;
             for (int j = 0; j < m; j++)
                 if (gans[j] == v[i]) {
                     ans[j] = sum;
                     break;
                 }*/

        }
    }

    for (int i = 0; i <  m; i++)
        cout << ans[i] << " ";

    return 0;
}



