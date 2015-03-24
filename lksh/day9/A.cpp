#include <iostream>
#include <cstdio>

long long f[21];
bool b[21];

int main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    long long ans = 0;

    f[1] = 1;
    for (int i = 2; i < 21; i++) {
        f[i] = i * f[i - 1];
        //td::cout << f[i] << " ";
    }
    int n;
    std::cin >> n;

    int p[n];

    //  bool li = false;

    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    /* for (int i = 0; i < n; i++) {
         if(p[i])
     }*/

    for (int i = 0; i < n; i++) {
        int l = 0;
        for (int j = 0; j < p[i]; j++) {
            if (b[j] == 0)
                l++;
        }
        b[p[i]] = true;
        ans += l * f[n - 1 - 1];
    }

    std::cout << ans << std::endl;

    fclose(stdout);
    return 0;
}
