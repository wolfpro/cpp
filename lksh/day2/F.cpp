#include <iostream>
#include <cstdio>
#include <algorithm>

struct Tim
{
    int v;
    int d;
    int id;
};

bool comp(Tim a, Tim b) {
    if (a.v == b.v)
        return a.d > b.d;

    return a.v >= b.v;
}

int main() {
    freopen("football.in", "r", stdin);
    freopen("football.out", "w", stdout);

    int n;
    std::cin >> n;

    Tim tim[n];

    for (int i = 0; i < n; i++) {
        std::cin >> tim[i].v;
        tim[i].id = i;
    }
    for (int i = 0; i < n; i++)
        std::cin >> tim[i].d;

    std::stable_sort(tim, tim + n, comp);

    for (int i = 0; i < n; i++)
        std ::cout << tim[i].id + 1 << " ";
    std::cout << std::endl;


    fclose(stdout);
    return 0;
}