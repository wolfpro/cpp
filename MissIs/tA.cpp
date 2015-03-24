#include <iostream>
#include <cstdio>

int main() {
    char t = 0;
    long long s = 0, num = 0, m = 1;
    while ((t = std::cin.get()) != EOF) {
        if (t == '-') {
            m = -1;
        } else {
            if (t != ' ' && t != '\n') {
                num = num * 10 + t - '0';
            } else {
                //  std::cout << num << std::endl;
                s += m * num;
                num = 0;
                m = 1;
            }
        }
    }
    // std::cout << num << std::endl;
    s += num;
    num = 0;
    std::cout << s << std::endl;
    return 0;
}