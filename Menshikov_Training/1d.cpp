#include <iostream>

struct Pair {
    long long x, y;
    void cin() {
        std::cin >> x >> y;
    }
};

long long ch(Pair a, Pair b, Pair c, Pair d) {
    Pair va;
    va.x = b.x - a.x;
    va.y = b.y - a.y;

    // std::cout << va.y *d.x  << " " <<  va.x *d.y << " " <<  va.x *a.y  << " " << va.y *a.x << '\n';
    //std::cout << (va.y * c.x - va.x * c.y - va.x * a.y - va.y * a.x) << " " << (va.y * d.x - va.x * d.y - va.x * a.y - va.y * a.x) << '\n';

    //std::cout << (va.y * c.x - va.x * c.y - va.x * a.y - va.y * a.x) * (va.y * d.x - va.x * d.y - va.x * a.y - va.y * a.x) << '\n';

    return (va.y * c.x - va.x * c.y + va.x * a.y - va.y * a.x) * (va.y * d.x - va.x * d.y + va.x * a.y - va.y * a.x);
}

int main() {
    Pair a, b, c, d;
    a.cin();
    b.cin();
    c.cin();
    d.cin();

    //a b, bc, ac
    if ((ch(a, b, c, d) >= 0 && ch(b, c, a, d) >= 0 && ch(a, c, b, d) >= 0)) {
        std::cout << "In\n";
    } else {
        std::cout << "Out\n";
    }


    return 0;
}