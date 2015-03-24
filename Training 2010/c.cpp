#include <iostream>
#include <algorithm>
#include <stack>

bool flag = false;

int d_t(int p, int t) {
    if ((p == 0 && t == 0) || (p == 1 && t == 1)) {
        flag = true;
        return 0;
    }
    if ((p == 2 && t == 0) || (p == 3 && t == 0)) {
        flag = true;

        return 1;
    }

    return -1;
}

int v0[101 * 1000];
int v1[101 * 1000];

int main() {
    /*
    0110

    00
    p -  r  t
    0 - 0 0
    1 - 0 1
    2 - 1 0
    3 - 1 1
    */
    std::stack <int> st;
    int a[4], n;
    std::cin >> n;
    for (int i = 0; i < 4; ++i) {
        char t;
        std::cin >> t;
        a[i] = t - '0';
        if (a[i] != 0)
            flag = true;
    }

    if (!flag) {
        std::cout << "No";
        return 0;
    }

    int now = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (a[j] == now) {
                if (j == 0 || j == 2)
                    st.push(0);
                else
                    st.push(1);

            }
        }
    }
    /*
    1 0
       1
    */

    return 0;
}