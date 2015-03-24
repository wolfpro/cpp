#include <iostream>
#include <string>

int main() {

    std::string r;

    r = "^-?(([1-9]+[0-9]*|(0))(\\.[0-9]*[1-9]+)?)$";

    std::cout << r << std::endl;

    return 0;
}