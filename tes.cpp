#include <iostream>
#include <cmath>

double mod(double a) {
    if (a < 0)
        a = -a;
    return a;
}

int main() {

    double g = 9.8, h1 = 750, h2 = 250, t1 = 0, t2 = 5.0;

    double H1 = h1 + g * t1 * t1 / 2;
    double H2 = h2 + g * (t1 + t2) * (t1 + t2) / 2;

    while (mod(H1 - H2) > 0.1 && (H1 - H2) >= 0) {
        t1 += 0.00001;
        H1 = h1 + g * t1 * t1 / 2;
        H2 = h2 + g * (t1 + t2) * (t1 + t2) / 2;
        std::cout << "h=" << t1 << "!\n";
    }

    std::cout << "ans h=" << H1 << " h2 = " << H2 << "!\n";
    return 0;
}