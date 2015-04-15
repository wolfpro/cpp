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
const double Pi = 3.14159265358979323846264338327950288;


int main() {
    double r, al;
    std::cout.precision(7);
    std::cin >> r >> al;
    std::cout << al << "\n";

    std::cout << ((int)(180 / (al) - 1)) * 2 * r*sin((al * Pi) / 180) + r << "\n";


    return 0;
}