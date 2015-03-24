#include <iostream>
#include <cstdio>
#include <vector>

bool f[5000][50000];

int d(int x, int y)
{
    if (x - y > 0)
        return x - y;
    return y - x;
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n, m, xa, xb, ya, yb;
    std::cin >> n >> m >> xa >> ya >> xb >>  yb;

    int s0 = d(xa, xb) + d(ya, yb);
    int s1 = d(ya, yb) + n + xa - xb;
    int s2 = d(xa, xb) + m + ya - yb;
    int s3 = d(ya, yb) + n + xb - xa;
    int s4 = d(xa, xb) + m + yb - ya;
    int s5 = d(xa + n, xb) + d(ya + m, yb);
    int s6 = d(xa, xb + n) + d(ya, yb + m);
    int s7 = d(xa + n, xb) + d(ya, yb + m);
    /*std::cout << s0 << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 <<  std::endl;
    std::cout << s3 <<  std::endl;
    std::cout << s4 <<  std::endl;
    std::cout << s5 <<  std::endl;
    std::cout << s6 <<  std::endl;*/

    int ans = std::min(s0, std::min(s1, std::min(s2, std::min(s3, std::min(s4, std::min(s5, std::min(s7, s6)))))));
    std::cout <<  ans / 2 + ans % 2 << std::endl;

    return 0;
}