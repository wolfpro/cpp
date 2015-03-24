#include <iostream>

bool m[1000001] = {0};

int main() {


    for (int i = 2; i < 1000001; ++i) {
        int k = 2;
        while (i * k <= 1000001) {
            m[i * k] = true;
            ++k;
        }

    }

    int n;
    std::cin >> n;

    for (int i = 4; i <= n; i++) {
        if (m[i] == 1 && (m[n - i] == 1)) {
            std::cout << i << " " << n - i << std::endl;
            break;
        }
    }

    /* std::cout << "{";
     for (int i = 2; i < 100001; ++i) {
         std::cout << m[i] << ", ";
     }
     std::cout << "};\n";*/
    return 0;
}