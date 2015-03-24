#include <iostream>
#include <cstdio>

using namespace std;

int rop[10002];
int ma = -1;
int n, k;

int item(int len)
{
  int a = 0;
  for (int i = 0; i < n; i++) {
    a += (rop[i] / len);
  }
  return a;
}

int max(int a, int b)
{
  if (a >= b)
    return a;
  else
    return b;
}

int main()
{
  freopen("ropes.in", "r", stdin);
  freopen("ropes.out", "w", stdout);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> rop[i];
    ma = max(ma, rop[i]);
  }

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (rop[i] > rop[j]) {
        int f = rop[j];
        rop[j] = rop[i];
        rop[i] = f;
      }

 /* for (int i = 0; i < n; i++) {
    cout << rop[i] << " ";
  }*/

  int l = 1, r = ma, m = l + (r - l) / 2;
  int t;
  while ((r - l) > 1) {
    m = l + (r - l) / 2;
    t = item(m);
    if (t < k)
      r = m;
    else
      l = m;
  }

  if (t == k) {
    if (item(r) == k) {
      cout << r << endl;
    } else {
      cout << l << endl;
    }
  } else
    cout << "0" << endl;

  fclose(stdout);
  return 0;
}