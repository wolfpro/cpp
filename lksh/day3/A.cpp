#include <iostream>
#include <string>

using namespace std;



int main () {
    int a [300];
    string s;

    cin >> s;
    char st[s.size];
    int h = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[')
            st[h++] = s[i];
        else {
            if (h == 0 || s[i] != st[h--])
                cout << "NO";
        }
    }
    cout << s.size() << endl;

    return 0;
}