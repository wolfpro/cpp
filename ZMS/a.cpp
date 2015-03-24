#include <iostream>
#include <vector>
#include <algorithm>

struct Dot
{
    int x;
    bool type;
    bool used;

};

bool comp(Dot a, Dot b) {
    if (a.x < b.x || (a.x == b.x && a.type < b.type)) {
        return 1;
    }
    return 0;

}

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<Dot> v;
    v.reserve(n);
    for (int i = 0; i < n - 1; ++i) {
        Dot a, b;
        a.type = 0;
        b.type = 1;
        std::cin >> a.x >> b.x;
        v.push_back(a);
        v.push_back(b);
    }
    int t = v.size();

    std::stable_sort(v.begin(), v.end(), comp);

    int ans = 0;

    int ls = 0;
    for (int i = 1; i < v.size(); ++i)


        return 0;
}