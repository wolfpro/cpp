#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main() {

    std::ios_base::sync_with_stdio(false);
    long long n, m;
    std::cin >> n >> m;

    std::vector < std::vector<long long> > v(n);
    long long used[n][11];
    long long lev[n];
    long long ans[n][11];

    for (int i = 0; i < n; ++i)
        for (int le = 0; le < 11; ++le) {
            used[i][le] = -1;
            ans[i][le] = -1;
            lev[i] = 1;
        }

    for (long long i = 0; i < m; ++i) {
        long long a, b;
        std::cin >> a >> b;
        --a, --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    std::queue <long long> q;

    long long A;
    std::cin >> A;

    for (long long i = 0; i < A; ++i) {
        long long t;
        std::cin >> t;
        --t;
        q.push(-t);
        used[t][0] = 0;
        ans[t][0] = t;
        lev[t]++;
    }

    long long k;
    std::cin >> k;

    if (k < A)
        while (!q.empty()) {
            long long t = -q.front();
            q.pop();

            for (long long le_t = 0; le_t < lev[t] && le_t <= k; ++le_t) {
                bool fl = true;
                if (used[t][le_t] > -1)
                    for (long long i = 0; i < v[t].size(); ++i)
                        for (long long le = 0; le < lev[i] && le <= k; ++le) {
                            if (used[v[t][i]][le] == -1) {
                                used[v[t][i]][le] = used[t][le_t] + 1;
                                ans[v[t][i]][le] = ans[t][le_t];
                                q.push(-v[t][i]);
                                lev[i]++;
                                fl = false;
                                break;
                            } else {
                                if (used[v[t][i]][le] > used[t][le_t] + 1 || (used[v[t][i]][le] == used[t][le_t] + 1 && ans[t][le_t] < ans[v[t][i]][le])) {
                                    used[v[t][i]][le] = used[t][le_t] + 1;
                                    ans[v[t][i]][le] = ans[t][le_t];
                                    q.push(-v[t][i]);
                                    lev[i]++;
                                    fl = false;
                                    break;
                                }
                            }
                        }
                if (!fl)
                    break;
            }
        }

    for (long long i = 0; i < n; ++i) {
        /*  if (used[i].size() <= k) {
              std::cout << "-1 ";
              continue;
          }
          std::cout << used[i][k] + 1 << " ";*/
        if (lev[i] <= k || ans[i][k] == -1) {
            std::cout << "-1 ";
        } else
            std::cout << ans[i][k] + 1 << " ";
    }

    std::cout << '\n';

    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < lev[i]; ++j)
            std::cout << ans[i][j] + 1 << " ";
        std::cout << '\n';
    }
    std::cout << '\n';
    return 0;
}