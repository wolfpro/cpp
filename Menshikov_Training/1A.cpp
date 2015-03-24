#include <iostream>
#include <cstdio>

const int SIZE = 1000001;

bool m[SIZE];

int main() {

    int a, b;
    std::cin >> a >> b;

    for (int i = 2; i * i < SIZE; ++i) {
        for (int j = 2; j * i < SIZE; ++j) {
            m[i * j] = 1;
        }
    }

    bool out = false;
    for (int i = a; i <= b; ++i) {
        if (m[i] == 0) {
            std::cout << i << "\n";
            out = true;
        }
    }

    if (!out) {
        std::cout << "Absent\n";
    }

    return 0;
}