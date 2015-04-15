#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>

typedef long long LL;
#define puba push_back
#define mapa std::make_pair
#define ff first
#define ss second


int main() {
    double r, al;
    std::cin >> r >> al;
    std::cout << 2 * sin(al * 0.017453292519943)*r *(180 / al - 1) << "\n";


    return 0;
}