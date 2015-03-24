#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main () {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);

    int a [300];
    string s;

    cin >> s;
    char st[s.size()];
    int h = 0;

    if (s.size() % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st[h++] = s[i];
        else {
            if (h > 0) {
                char t = st[--h];
                if ((s[i] == ')' && t != '(') || (s[i] == ']' && t != '[') || (s[i] == '}' && t != '{')) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (h > 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    fclose(stdout);
    return 0;
}