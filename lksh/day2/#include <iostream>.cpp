#include <iostream>
#include <vector>

#define pub push_back

int a = 12345, b = 123;

int pow(int x, int n) {
    for (int i = 1, m = x; i < n; ++i)
        x *= m;
    return x;
}

int main() {
    int n;
    std::cin >> n;
    int one = 0, two = 0;

    int k1 = 0, k2 = 1;
    one = one + pow(k1 + 1, 2) % a;
    two = two + pow(k2 + 1, 3) % b;


    while (k1 + k2 < n) {
        while (two > one) {
            one = one + pow(++k1 + 1, 2) % a;
            if (k1 + k2 == n) {
                std::cout << one << '\n';
                return 0;
            }
        }
        two = two + pow(++k2 + 1, 3) % b;
        if (k1 + k2 == n) {
            std::cout << two << '\n';
            return 0;
        }
        std::cout << one << " " << two << '\n';
    }

    /*for (int i = 1; i < n; ++i) {
        one = one + pow(i + 1, 2) % a;
        two = two + pow(i + 1, 3) % b;

        std::cout << one << " " << two << '\n';
    }*/



    return 0;
}