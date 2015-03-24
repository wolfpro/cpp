#include <iostream>
#include <algorithm>

bool comp(int a, int b) {
    return a > b;
}

int main() {

    int n, k;
    std::cin >> n >> k;

    int f[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i];
    }

    std::sort(f, f + n, comp);

    // for (int i = 0; i < n; ++i ) {
    //     std::cout << f[i] << " ";
    // }

    int tim = 0;
    int que [k];
    int q = 0;
    int mf = 1;

    for (int i = 0; i < n; ++i ) {
        if (q < k) {
            que[q] = f[i];
            ++q;
        } else {
            mf = 1;
            for (int j = 0; j < q; ++j) {
                if (que[j] > mf) {
                    // tim += (que[j] - mf);
                    mf = que[j];
                }
            }
            q = 0;
            tim += mf - 1;
            tim += mf - 1;

            // std::cout << mf << "f\n";
            que[q] = f[i];
            ++q;
        }
    }
    //std::cout << q;

    if (q > 0) {
        mf = 1;
        for (int j = 0; j < q; ++j) {
            if (que[j] > mf) {
                // tim += (que[j] - mf);
                mf = que[j];
            }
        }
        q = 0;
        tim += mf - 1;
        tim += mf - 1;
    }

    std::cout << tim;

    std::cout << std::endl;
    return 0;
}