#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

int main() {
    freopen("topsort.in", "r", stdin);
    // freopen("topsort.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;

    std::vector < std::vector<int> > v;
    v.resize(n);

    for (int i = 0, a, b; i < m; i++) {
        std::cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
    }

    bool us[n];
    int ans[n], ind = -1;

    for (int i = 0; i < n; i++)
        us[i] = false;

    for (int i = 0; i < n; i++) {
        if (!us[i]) {
            std::stack <int> st;

            st.push(i);

            while (st.size()) {
                int t = st.top();
                st.pop();
                ans[++ind] = t + 1;
                us[t] = true;
                for (int j = 0; j < v[t].size(); j++) {
                    if (!us[v[t][j]]) {
                        st.push(v[t][j]);
                    }
                }
            }
        }
    }
    for (int i = n; i > 0;  --i) {
        std::cout << ans[i - 1] << " ";
    }
    std::cout << std::endl;

    return 0;
}
