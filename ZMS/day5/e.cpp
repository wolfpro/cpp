#include <iostream>
#include <string>

int main() {
    std::string s = "^(:|;)-?(\\\\)|\\\\(|\\\\/|\\\\\\\\|\\\\||D)+$";
    s = "^(:|;)-?(\\)+|\\(+|\\/+|\\\\+|\\|+|D+)$";

    /*   std::regex r(s);
       std::cin >> s;*/

    std::cout << s << std::endl;


    return 0;
}