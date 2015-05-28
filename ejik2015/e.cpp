#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
#include <queue>

typedef long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second
const double Pi = 3.14159265358979323846264338327950288;

int main() {
    int n;
    std::cin >> n;
    std::priority_queue <std::pair<int, int> > q;
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        q.push(std::make_pair(t, i));
    }

    std::cout << v.size() << "\n";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    return 0;
}