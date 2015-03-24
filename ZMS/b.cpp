#include <iostream>

long long mod(long long a, long long b) {
    a = a - b;
    if (a > 0)
        return a;
    return 0 - a;
}

int main() {
    long long n;
    std::cin >> n;

    long long mike_array[n];
    for (long long i = 0; i < n; ++i) {
        std::cin >> mike_array[i];
    }

    long long m;
    std::cin >> m;
    long long shot_array[m];
    for (long long i = 0; i < m; ++i) {
        std::cin >> shot_array[i];
    }
    long long mike, shot, mo  = 1000 * 1000 * 1000 + 1;

    for (int i = 0, j = 0; (i < n) && (j >= 0) ;) {
        int a = i, b = j;
        if (mod(mike_array[a], shot_array[b]) <= mo) {
            mike = mike_array[a];
            shot = shot_array[b];
            mo = mod(mike_array[a], shot_array[b]);
        }
        if (mike_array[a] < shot_array[b])
            if (i < n - 1)
                i++;
        if (mike_array[a] > shot_array[b])
            if (j < m - 1)
                j++;
        if (a == i && b == j) {
            break;
        }
    }

    std::cout << mike << " " << shot << std::endl;
    return 0;
}