#include <iostream>
#include <cstdio>

int col[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//            ........0  1  2  3  4  5  6  7  8  9
int n, k;
int num[101];

void prin() {
    for (int i = 0; i < n; ++i)
        std::cout << num[i];
    std::cout << std::endl;
}

int main() {
    std::cin >> n >> k;
    int ans = 0, ans1 = 0;
    int used[n];

    for (int i = 0; i < n; ++i) {
        num[i] = 9;
        ans += col[9];
        ans1 += col[1];
        used[i] = 0;
    }
    if (ans < k || ans1 > k) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }
    int tans = 0;
    bool flag = false;

    for (int i = 0; i < n; ++i) {
        flag = false;
        for (int j = num[i]; j >= 0; --j) {
            if (col[j] + tans <= k) {
                used[i] = col[j];
                num[i] = j;
                tans += col[j];
                flag = true;
                break;
            }
        }
        if (!flag) {
            /* prin();
             std::cout << tans  << " " << i << std::endl;
            */
            tans -= used[i - 1];
            used[i] = 0;
            num[i - 1]--;
            num[i] = 9;
            i -= 2;
        }
    }
    prin();

    for (int i = 0; i < n; ++i) {
        used[i] = 0;
        num[i] = 0;
    }
    num[0] = 1;
    tans = 0;

    for (int i = 0; i <= n; ++i) {
        flag = false;
        for (int j = 0; j <= 9; ++j) {
            if (col[j] + tans <= k) {
                tans -= used[i - 1];
                used[i] = col[j];
                num[i] = j;
                tans += col[j];
                flag = true;
                continue;
            }
        }
        if (!flag) {
            if (k == tans && n - 1 == i)
                break;
            /* prin();
             std::cout << tans  << " " << i << std::endl;
            */
            tans -= used[i - 1];
            used[i] = 0;
            num[i + 1]++;
            num[i] = 0;
            i += 2;
        }

    }


    prin();


    return 0;
}