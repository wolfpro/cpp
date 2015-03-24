#include <iostream>
#include <string>

int main() {

    std::string a, b;
    std::cin >> a >> b;
    int len_a = a.size(), len_b = b.size();

    while (len_a > 2 && len_b > 2) {
        if (b[len_b - 1] == '0')
            len_b--;

        if (a[len_a - 1] == '0')
            len_a--;

        if (b[len_b - 1] == '1' && a[len_a - 1] == '1') {
            if (len_a < len_b) {
                std::string t = a;
                a = b;
                b = t;
                int tt = len_a;
                len_a = len_b;
                len_b = tt;
            }

            int p = 0;
            for (int i = 1; i <= len_b; ++i) {
                if (p == 1) {
                    if (a[len_a - i] == '1') {
                        a[len_a - i] = '0';
                        p = 0;
                    }
                }
                if (a[len_a - i] == b[len_b - i])
                    a[len_a - i] = '0';
                if (a[len_a - i] == '1' && b[len_b - i] == '0')
                    a[len_a - i] = '1';
                else {
                    a[len_a - i] = '1';
                    p = 1;
                }
            }

            if (p == 1) {
                for (int i = len_b ; i < len_a; ++i) {
                    if (a[len_a - i] == '1') {
                        a[len_a - i] == '0';
                    }
                }
            }

            for (int i = len_a; i >= 0; --i) {
                if (a[len_a - 1] == '0')
                    len_a--;
                else
                    break;
            }
            for (int i = len_b; i >= 0; --i) {
                if (b[len_b - 1] == '0')
                    len_b--;
                else
                    break;
            }
        }

        if (len_a > 0) {
            for (int i = 0; i <= len_a; ++i)
                std::cout << a[i];
            std::cout << std::endl;
        } else {
            for (int i = len_b; i >= 0; ++i)
                std::cout << b[i];
            std::cout << std::endl;
        }
    }


    return 0;
}