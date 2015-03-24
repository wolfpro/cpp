3#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

const int MEM_SIZE = 250 * 1024 * 1024;
size_t NOW_MEM = 0;
char MEM[MEM_SIZE];

inline void *operator new(size_t l) {
    NOW_MEM += l;
    assert(NOW_MEM <= MEM_SIZE);
    return MEM + NOW_MEM - l;
}

inline void operator delete(void *) {

}

typedef long long LL;

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::priority_queue<LL> v;

    for (int i = 0; i < k; ++i)
        v.push(0);

    LL cur = 0, a, b;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        cur = 0 - v.top();
        v.pop();
        if (cur < a)
            cur += (a - cur);
        cur += b;
        std::cout << cur << '\n';
        v.push(0 - cur);
    }

    return 0;
}