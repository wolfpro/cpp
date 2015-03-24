#include <iostream>
#include <cstdio>

struct Cord {
    double x, y, k;
    /* data */
    void scan()
    {
        std::cin >> x >> y;
    }

    double getK(Cord a)
    {
        if (a.x - x == 0) {
            a.x += 0.000000000000001;
        }
        return ((a.y - y) / (a.x - x));
    }
};

Cord aA, aB, aC;

void sort(Cord *a, Cord *b, Cord *c)
{
    Cord t;
    t.x = a->x;
    t.y = a->y;

    if (t.y < b->y) {
        t.x = b->x;
        t.y = b->y;
    }

    if (t.y < c->y) {
        t.x = c->x;
        t.y = c->y;
    }


    aB.x = t.x;
    aB.y = t.y; //B is it

    if ((t.x < b->x) && (t.x != b->x || t.y != b->y)) {
        t.x = b->x;
        t.y = b->y;
    }

    if ((t.x < c->x) && (t.x != c->x || t.y != c->y)) {
        t.x = c->x;
        t.y = c->y;
    }

    if ((t.x < a->x) && (t.x != a->x || t.y != a->y)) {
        t.x = a->x;
        t.y = a->y;
    }

    aC.x = t.x;
    aC.y = t.y;

    if ((a->x != aB.x || a->y != aB.y) && (a->x != aC.x || a->y != aC.y)) {
        aA.x = a->x;
        aA.y = a->y;
    }

    if ((b->x != aB.x || b->y != aB.y) && (b->x != aC.x || b->y != aC.y)) {
        aA.x = b->x;
        aA.y = b->y;
    }

    if ((c->x != aB.x || c->y != aB.y) && (c->x != aC.x || c->y != aC.y)) {
        aA.x = c->x;
        aA.y = c->y;
    }

    a = &aA;
    b = &aB;
    c = &aB;
}

int main()
{
    freopen("input.txt", "r", stdin);
    Cord a, b, c, d;
    a.scan();
    b.scan();
    c.scan();
    d.scan();

    sort(&a, &b, &c);


    /*std::cout << a.x << " " << a.y << "\n";
    std::cout << b.x << " " << b.y << "\n";
    std::cout << c.x << " " << c.y << "\n";

    std::cout << a.getK(d) << " " << a.getK(c) << "\n";*/

    //  if ((a.getK(d) >= a.getK(c)) && (a.getK(d) <= a.getK(b)) && (b.getK(d) <= b.getK(c))) {
    // std::cout << "In\n";
    //return 0;
    //  }

    std::cout << "Out\n";
    return 0;
}