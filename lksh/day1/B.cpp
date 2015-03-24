#include <iostream>
#include <cstdio>

using namespace std;

long long  bat[100001];
long long  n;

bool ch(int t){

  long long l = 0, m = 0, r = n;

  while ((r - l) > 1) {
    m = l + (r - l) / 2;

    if (bat[m] == t || bat[l] == t || bat[r - 1] == t) {
      return true;
    }

    if (bat[m] > t) {
      r = m;
    } else
      l = m;
  }

  if (bat[l] == t ) {
    return true;
  }
  return false;
}

int main(){

  freopen("collect.in", "r", stdin);
  freopen("collect.out", "w", stdout);
  cin >> n;

  for (long long i = 0; i < n; i++) {
    cin >> bat[i];
  }

  long long m;
  cin >> m;

  for (long long i = 0, t = 0; i < m; i++) {
    cin >> t;
    if (ch(t)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    if (i < m - 1)
      cout << endl;
  }

  fclose(stdout); // recommended but often not needed. Ensures that output file will be saved.
  return 0;
}