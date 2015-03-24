#include <iostream>
#include <cassert>

const int MEM_SIZE = 240 * 1024 * 1024;
size_t NOW_MEM = 0;
char MEM[MEM_SIZE];

inline void *operator new(size_t l) {
    NOW_MEM += l;
    assert(NOW_MEM <= MEM_SIZE);
    return MEM + NOW_MEM - l;
}

inline void operator delete(void *) {

}

int main() {
    int n = 121;
    std::cout << n << std::endl;

    return 0;
}