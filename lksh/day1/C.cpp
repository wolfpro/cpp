#include <iostream>
#include <cstdio>

using namespace std;

long long c[100000 + 1];
long long v[100000 + 1];

int main(){
  freopen("mutants.in", "r", stdin);
  freopen("mutants.out", "w", stdout);

  long long ans = 0;
  long long n = 0;
  cin >> n;

  if (n == 0) {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++)
      cout << "0\n";
    return 0;
  }



  /* for (long long i = 0; i < n + 1; i++) {
     c[i] = 0;
     v[i] = 0;
   }*/

  long long lc;
  long long li = 0;

  cin >> lc;
  c[0]++;
  v[0] = lc;

  for (long long i = 1, t = 0; i < n; i++)  {
    cin >> t;
    if (lc == t) {
      c[li]++;
      v[li] = t;
    } else {
      c[++li]++;
      v[li] = t;
      lc = t;
    }
  }

  /*for (long long i = 0; i < li + 1; i++)
    cout << c[i] << " ";
  cout << endl;

  for (long long i = 0; i < li + 1; i++)
    cout << v[i] << " ";
  cout << endl;*/

  long long lm = 0;
  cin >> lm;

  for (long long i = 0, t = 0; i < lm; i++) {
    cin >> t;

    long long l = 0, r = li + 1, m = l + (r - l) / 2;

    while ((r - l) > 1) {
      m = l + (r - l) / 2;
      if (v[m] > t)
        r = m;
      else
        l = m;
    }

    if (v[l] == t)
      cout << c[l] << endl;
    else
      cout << "0\n";
  }

  fclose(stdout);
  return 0;
}