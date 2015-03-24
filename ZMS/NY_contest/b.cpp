#include <string>
#include <cstdio>
#include <iostream>

int main() {
    while (true) {
        std::string a, b, c;
        std::cin >> a  >> b;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] >= 97) {
                c += (a[i] - 'A');
            } else
                c += a[i];
        }
        a = b;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] >= 97) {
                c += a[i] - 'A';
            } else
                c += a[i];
        }
        std::cout << c << std::endl;
    }
    std::cout << 'a' + 0 << std::endl;
    return 0;
}