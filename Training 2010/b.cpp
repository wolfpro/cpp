#include <iostream>

long long w, h, n;

bool check(long long L) {
    // long long count = L / w + L / h;
    if ((L / w) * (L / h) < n)
        return false;
    return true;
}



int main() {
    std::cin >> w >> h >> n;

    long long l = 1, r = (long long) (h + w) * n;
    long long  mid = l + (r - l) / 2;;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //std::cout << l << std::endl;
    if (check(l))
        std::cout << l << std::endl;
    else
        std::cout << r << std::endl;
    return 0;
}