#include <iostream>
#include <vector>

int main() {
    std::vector<int> v(3, 100);

    v.insert(v.begin() + v.size() / 2 + v.size() % 2, 200);

    for (int i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';



    return 0;
}