#include <fstream>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

ifstream in;

void opn(string dpath) {
    in.open(dpath);
}

int main() {
    /*std::string path = "/home/wolfpro/cod/City 2014/tests/", dpath;
    for (int i = 101; i < 152; ++i ) {
        dpath = "";
        char c = (i / 10) % 10 + '0';
        dpath += c;
        c = i % 10 + '0';
        dpath += c;

        opn(dpath);

        std::cout << dpath << "\n";
        string s;

        int k = 0;
        while (getchar(in, c))
            cout << s << '\n';
        cout << "\n";

        in.close();*/
    clock_t t0 = clock();

    clock_t t1 = clock();
    cout << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    return 0;
}