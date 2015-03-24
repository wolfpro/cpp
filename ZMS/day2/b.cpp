#include <iostream>
#include <cstdio>
#include <queue>

std::priority_queue <int> q;

int main()
{
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);

    int n;
    std::cin >> n;

    for (int i = 0, a; i < n; ++i) {
        std::cin >> a;
        a = -a;
        q.push(a);
    }

    double answ = 0;

    int re = 1;

    while (!q.empty()) {
        if (q.size() == 1) {
            break;
        }

        int tt = q.top();
        q.pop();
        tt += q.top();
        q.pop();

        q.push(tt);
        tt = -tt;
        if (re < n) {
            answ += (0.05 * (tt));
        }
        ++re;
    }

    printf("%.2lf\n",  answ);
    fclose(stdout);
    return 0;
}
