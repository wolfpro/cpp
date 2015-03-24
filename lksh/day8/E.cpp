#include <iostream>
#include <string>
#include <cstdio>

std::string prev(std::string s) {
    if (s.size() == 2) {
        std::cout << s << std::endl;
        return s;
    }
    long long i = s.size() - 2;
    long long cz = 0, co = 0;
    while (i > -1 && s[i] <= s[i + 1]) {
        if (s[i] == '(')
            co++;
        else
            cz++;
        i--;
    }
    co;

    if (i == -1) {
        std::string ss;
        for (int j = 0; j < s.size() / 2; j++) {
            //   std::cout << "()";
            ss.push_back('(');
            ss.push_back(')');
        }
        // std::cout << std::endl;

        return ss;
    }

    std::swap(s[i], s[i + 1]);
    i++;
    while (co) {
        s[i++] = ')';
        co--;
    }
    while (cz) {
        s[i++] = '(';
        cz--;
    }
    //std::cout << s << std::endl;
    return s;

}

int main() {
    freopen("prev.in", "r", stdin);
    freopen("prev.out", "w", stdout);

    std::string s, s2;
    std::cin >> s;
    //  std::cin >> s;
    s2 = prev(s);
    /* while (s == s2) {
         //  if (s == s2) {
         std::cin >> s;
         s2 = prev(s);
     }*/

    //std::cout << s << std::endl;
    std::cout << s2 << std::endl;

    //fclose(stdout);
    return 0;
}