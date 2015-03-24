#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct  Pair
{
    int x;
    int y;
};

bool comp(Pair a, Pair b) {
    return a.x < b.x;
}

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    int n;
    cin >> n;
    Pair p[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x;
        cin >> p[i].y;
    }

    std::stable_sort(p, p + n, comp);

    for (int i = 0; i < n; i++) {
        cout << p[i].x << " " << p[i].y << endl;
    }


    fclose(stdout);
    return 0;
}