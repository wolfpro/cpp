#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> v;
    std::vector<int> c;

    v.reserve(n + 1);
    c.reserve(n + 1);

    v.push_back(0);
    c.push_back(0);

    int t;
    for (int i = 1; i <= n; ++i) {
        std::cin >> t;
        v.push_back(t);
        c.push_back(0);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j > -1; --j) {
            if (v[j] < v[i]) {
                c[i] = std::max(c[j] + 1, c[i]);
            }
        }
    }

    int ans = 0;
    int va = 0;
    for (int i = 0; i <= n; ++i) {
        if (c[i] > ans) {
            ans = c[i];
            va = v[i];
        }
    }
    int an[ans];
    va++;
    int p = ans - 1, taa = ans;;
    //for (int i = )
    /*for (int i = 0; i <= n; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i <= n; ++i) {
        std::cout << c[i] << " ";
    }*/
    for (int i = n; i > 0; --i) {
        if (c[i] == ans && v[i] < va) {
            an[p--] = v[i];
            ans--;
        }
    }
    ans = taa;
    std::cout << ans << std::endl;

    for (int i = 0; i < ans; ++i) {
        std::cout << an[i] << " ";
    }
    std::cout <<  std::endl;

    return 0;
}