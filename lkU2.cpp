#include <iostream>

void pr(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return;
    }
    std::cout << a << std::endl;
}

int main() {
    for (int s = 1; s < 3; s++) {
        for (int i = 0; i < 10; i++)
            pr((i + s) * 1000 + (i + s * 2)  * 100  + (i + s * 3)  * 10 + (i + s * 4));
    }

    return 0;
}