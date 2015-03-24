#include <iostream>
#include <vector>

int main() {
    int n = 10 * 1000 * 1000;
    std::vector<int> lp(n + 1, 0);
    std::vector<int> pr;

    pr.reserve(1024);

    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j)
            lp[i * pr[j]] = pr[j];
    }

    for (int i = 0; i < 10; ++i)
        std::cout << pr[i] << " ";
    std::cout << '\n';

    return 0;
}