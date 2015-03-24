#include <iostream>
#include <vector>


int main() {
    std::vector<double> v(19, 0);

    for (int a = 1; a < 7; ++a)
        for (int b = 1; b < 7; ++b)
            for (int c = 1; c < 7; ++c) {
                v[a + b + c]++;
            }

    for (int i = 1; i < 19; ++i)
        v[i] += v[i - 1];

    for (int i = 0; i < 18; ++i)     {
        std::cout << i + 1  << ":" << (double)(v[i + 1] * 1.0 / 216) << '\n';
    }

    return 0;
}