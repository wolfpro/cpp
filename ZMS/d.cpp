#include <iostream>
#include <deque>

struct Pair {
    int v;
    int id;
};

int main() {
    int n, k;
    std::cin >> n >> k;

    std::deque <Pair> deque;
    /*push_   pop_ back front*/
    Pair t;
    std::cin >> t.v;
    t.id = 0;
    deque.push_back(t);
    int l = 0, r = 1;

    if (n == 1) {
        std::cout << deque.front().v << std::endl;
        return 0;
    }

    for (int i = r; i < k; ++i, r++) {
        std::cin >> t.v;
        t.id = i;
        while (!deque.empty() && deque.back().v > t.v) {
            deque.pop_back();
        }
        deque.push_back(t);
    }
    if (!deque.empty() && deque.front().id < l)
        deque.pop_front();
    std::cout << deque.front().v << std::endl;
    l++;

    for (; r < n; ++r, ++l) {
        std::cin >> t.v;
        t.id = r;
        while (!deque.empty() && deque.back().v > t.v) {
            deque.pop_back();
        }
        deque.push_back(t);
        if (!deque.empty() && deque.front().id < l)
            deque.pop_front();
        std::cout << deque.front().v << std::endl;
    }
    /*  if (!deque.empty() && deque.front().id < n - 1)
          deque.pop_front();
      std::cout << deque.front().v << std::endl;*/
    return 0;

}