#include <iostream>

int main() {
    int ans = 0;
    for (int i = 0; i < 44444445; ++i) {
        int a = 0, b = 0, c = 0, d = 0;
        for (int j = 0, t = i, ct = i % 10; j < 8; ++j) {
            if (t % 10 == ct)
                break;
            else {
                ct = t % 10;
                t /= 10;
            }


        }
    }



    return 0;
}