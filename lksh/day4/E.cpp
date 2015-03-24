#include <iostream>
#include <stack>
#include <cstdio>

int main() {
    freopen("calcul.in", "r", stdin);
    freopen("calcul.out", "w", stdout);

    int n;
    std::cin >> n;

    int c[n + 2];
    int p[n + 2];

    for (int i = 0; i <= n; i++) {
        c[i] = 1000 * 1000 * 2;
        p[i] = 0;
    }

    c[1] = 0;

    for (int i = 1; i <= n; i++) {
        if (i + 1 <= n) {
            c[i + 1] = std::min(c[i + 1], c[i] + 1);
            if (std::min(c[i + 1], c[i] + 1) == c[i] + 1)
                p[i + 1] = i;
        }

        if (i * 2 <= n) {
            c[i * 2] = std::min(c[i * 2], c[i] + 1);
            if (std::min(c[i * 2], c[i] + 1) == c[i] + 1)
                p[i * 2] = i;
        }

        if (i * 3 <= n) {
            c[i * 3] = std::min(c[i * 3], c[i] + 1);
            if (std::min(c[i * 3], c[i] + 1) == c[i] + 1)
                p[i * 3] = i;
        }
    }


    std::stack <int> st;
    {
        int i = n;
        while (i > 0) {
            st.push(i);
            i = p[i];
        }
    }

    std :: cout << c[n] << std::endl;

    /*for (int i = 1; i <= n; ++i)
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;*/

    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;

    fclose(stdout);
    return 0;
}