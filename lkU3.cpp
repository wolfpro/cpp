#include <iostream>
#include <cmath>

int a[5] = {1, 2, 3, 4, 5};
int b[5] = {0, 2, 6, 14, 30};

int main() {
    int  i = 1;
    int min = 99999999, count = 0;;
    for (; i <= 256; i++) {
        for (int j = 0; j < 5; j++) {
            //std::cout << std::pow(2, a[j]) << std::endl  ;
            if ((i % (int)std::pow(2, a[j]) != b[j])) {
                break;
            }

            if (i % (int) std::pow(2, a[j]) == b[j]) {
                // std::cout << i / std::pow(2, a[j]) << " ";

                if (j == 4) {
                    std::cout << i << std::endl;
                    count++;
                    if (min > i)
                        min = i;
                }
            }
        }
    }

    std::cout << "min = " << min << "; all:" << count << ";\n";
    return 0;
}