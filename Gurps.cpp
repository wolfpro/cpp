#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int mod;
    std::cout << "d: ";
    std::cin >> mod;
    mod++;
    std::cout << "For exit: 0 0\n";

    int n = 1, x, def = 0;
    while (n) {
        std::cout << "Cubes: Min:\n";
        std::cin >> n >> x;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int rav = std::rand() % mod;
            ans += rav;
            std::cout << rav << " ";
        }
        std::cout << "\nsum:" << ans << " " << ans - x << "\n";
    }

    return 0;
}