#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

bool used[21];


int main() {

    /* std::ifstream cin("in.in");
     std::ofstream cout("out.out");
     */
    std::ios_base::sync_with_stdio(0);

    int n, k;
    std::cin >> n >> k;
    std::vector < std::vector<int> > v;
    v.resize(n);
    for (int i = n - 1; i >= 0; --i) {
        int t, tt;
        std::cin >> t;
        for (int j = 0; j < t; ++j) {
            std::cin >> tt;
            v[i].push_back(tt);
        }
    }

    int mask = (1 << (n)) - 1, sm = 0, ans = 0, ans_mask = 0, ans_people = 99999999;

    for (sm = mask; sm >= 0; --sm) {
        for (int j = 0; j < k; ++j)
            used[j] = 0;

        int us = 0, people = 0;

        for (int s = 0; s < n; ++s) {

            if ((sm & (1 << s)) != 0) {
                people++;

                for (int p = 0; p < v[s].size(); ++p) {
                    if (used[v[s][p] - 1] == 0)
                        us++;
                    used[v[s][p] - 1] = 1;
                }
            }
        }

        if (us == k) {
            if (ans_people >  people) {
                ans_people = people;
                ans_mask = sm;
            }
        }
    }

    std::cout << ans_people << std::endl;

    for (int s = n - 1; s >= 0; --s)
        if ((ans_mask & (1 << s)) > 0)
            std::cout << (n - s) << " ";
    std::cout << std::endl;

    return 0;
}