#include <iostream>
#include <vector>
int n, k, p = 0;
std::vector<int> v;

int r(int pos) {
    if (pos == n) {
        k++;
    }
}

int main() {
    std::cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    p = 1;


    return 0;
}