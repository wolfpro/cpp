#include <iostream>
#include <fstream>

bool used[21];
int n, k;

bool game() {
    if (n % (k + 1) == 0) {
        return false;
    }
    return true;
}

int main() {

    /* std::ifstream cin("in.in");
     std::ofstream cout("out.out");
     */
    std::ios_base::sync_with_stdio(0);
    int t;
    std::cin >> t;

    int ans = 0;
    for (int i = 0; i < t; ++i) {

        std::cin >> n >> k;
        ans += game();
    }

    std::cout << ans << std::endl;

    return 0;
}