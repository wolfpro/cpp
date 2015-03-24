#include <iostream>
#include <cstring>

std::string s, t;
int main() {

    std::cin >> s >> t;

    int lg = 0, rg = 0;

    int cur = 0;
    for (int i = 0; i < (int)t.size(); ++i) {
        if (t[i] == s[cur])
            cur++;
        if (cur == (int)s.size()) {
            lg = i;
            // std::cout << lg << ' ';
            break;
        }
    }

    cur = 0;
    for (int i = (int) (t.size() - 1); i >= 0; --i) {
        if (t[i] == s[s.size() - 1 - cur])
            cur++;
        if (cur == (int)s.size()) {
            rg = i;
            //  std::cout << rg << '\n';
            break;
        }
    }

    std::cout << std::max(rg - lg, 0) << '\n';
    return 0;
}