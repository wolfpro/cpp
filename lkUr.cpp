#include <iostream>
int main() {
    int a = 1;
    for (int i = 0; i < 10; ++i) {
        for (int q = 0; q < 10; ++q)
            for (int w = 0; w < 10; ++w)
                for (int e = 0; e < 10; ++e)
                    for (int r = 0; r < 10; ++r) {
                        if ((a * 100000 + i * 10000 + q * 1000 + w * 100 + e * 10 + r) * 3 ==  i * 100000 + q * 10000 + w * 1000 + e * 100 + r * 10 + a ) {
                            std::cout << a << i << q << w << e << r << std::endl;
                        }
                    }
    }

    return 0;
}