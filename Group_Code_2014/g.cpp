#include <iostream>
#include <vector>
#include <algorithm>

struct Pep {
    long long v;
    long long id;
    long long coin;
    bool is_pet;

    void make_Pep(long long i) {
        std::cin >> v;
        id = i;
        coin = 0;
        is_pet = false;
    }
};

bool comp(Pep a, Pep b) {
    if (a.v < b.v)
        return 1;
    if (a.v == b.v) {
        return a.is_pet;
    }
    return a.v < b.v;
}

bool comp_id(Pep a, Pep b) {
    return a.id < b.id;
}

int main() {

    long long n, m, k;
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> m >> k;

    std::vector<Pep> v(n);

    for (long long i = 0; i < n; ++i) {
        v[i].make_Pep(i);
    }

    for (long long i = 0; i < m; ++i) {
        long long t;
        std::cin >> t;
        --t;
        v[t].is_pet = true;
    }

    std::stable_sort(v.begin(), v.end(), comp);

    long long c = 0;
    v[0].coin = c;
    for (long long i = 1; i < n; ++i) {
        if (v[i].v != v[i - 1].v)
            ++c;

        if (k < c) {
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }
        v[i].coin = c;
        k -= c;
    }

    for (long long i = 0; i < n; ++i) {
        if (v[i].is_pet) {
            long long c = k / (n - i);
            for (long long j = i; j < n; ++j)
                v[j].coin += c;
            break;
        }
    }

    std::stable_sort(v.begin(), v.end(), comp_id);
    std::cout << "POSSIBLE\n";
    for (long long i = 0; i < n; ++i) {
        std::cout << v[i].coin << " ";
    }
    std::cout << '\n';

    return 0;
}