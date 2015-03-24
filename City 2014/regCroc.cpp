#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctime>
#include <fstream>

std::ifstream in;

int dx[4] = { -1, 0, 1, 0};//wnes
int dy[4] = {0, -1, 0, 1};

struct Pair {
    int x;
    int y;
    Pair(int a, int b) {
        x = a;
        y = b;
    }
};

int my(std::string path);
int other(std::string path);
int gen();

int main() {
    gen();

    return 0;
}

int my(std::string path) {
    //std::ios_base::sync_with_stdio(false);
    //freopen(path, "r", stdin);
    // std::ifstream in(path);
    // std::cout << in << "\n";
    //const time_t timer = time(NULL);
    int n, m;
    std::cin >> n >> m;
    int f[m][n];//0-4 - go, -1 = null, -2 = redCroc;
    for (int j = 0; j < n; ++j) {
        std::string s;
        getline(in, s);
        for (int i = 0; i < m; ++i) {
            char tc = s[i];
            //std::cin >> tc;
            if (tc == 'W')
                f[i][j] = 0;
            if (tc == 'N')
                f[i][j] = 1;
            if (tc == 'E')
                f[i][j] = 2;
            if (tc == 'S')
                f[i][j] = 3;
            if (tc == '.')
                f[i][j] = -1;
        }
    }
    // in.close();
    int ans = 0;
    for (int j = 0; j < n; ++j)
        for (int i = 0; i < m; ++i) {
            if (f[i][j] >= 0) {
                std::stack <Pair> st;
                st.push(Pair(i, j));
                while (!st.empty()) {
                    int  x = st.top().x, y = st.top().y, t = f[x][y];
                    f[x][y] = -2;

                    if (t == -2) {
                        while (!st.empty()) {
                            f[st.top().x][st.top().y] = -2;
                            st.pop();
                        }
                        break;
                    }
                    for (int w = 1;  w < 2002; ++w) {
                        if (w * dx[t] + x < 0 || w * dx[t] + x >= m || w * dy[t] + y < 0 || w * dy[t] + y >= n) {
                            while (!st.empty()) {
                                ans++;
                                f[st.top().x][st.top().y] = -1;
                                st.pop();
                            }
                            break;
                        }
                        if (f[w * dx[t] + x][w * dy[t] + y] >= 0) {
                            st.push(Pair(w * dx[t] + x, w * dy[t] + y));
                            break;
                        }
                        if (f[w * dx[t] + x][w * dy[t] + y] == -2) {
                            while (!st.empty()) {
                                f[st.top().x][st.top().y] = -2;
                                st.pop();
                            }
                            break;
                        }
                    }
                }
            }
        }
    //time_t timer2 = time(NULL);
    // std::cout << timer - timer2;
    // in.close();

    return ans;
}

const int N = 2010;

std::string a[N];
int nxt_left[N], nxt_right[N];
int nxt_up[N], nxt_down[N];

int other(std::string path) {

    //std::ifstream in(path);

    //std::cout << path  << "2\n";

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
        getline(in, a[i]);
    //scanf("%s", a[i]);

    for (int i = 0; i < n; ++i)
    {
        nxt_left[i] = 0;
        nxt_right[i] = m - 1;
    }
    for (int i = 0; i < m; ++i)
    {
        nxt_up[i] = 0;
        nxt_down[i] = n - 1;
    }

    int oldans = -1;
    int ans = 0;
    while (oldans != ans)
    {
        oldans = ans;
        for (int i = 0; i < n; ++i)
        {
            while (nxt_left[i] <= nxt_right[i] && (a[i][nxt_left[i]] == '.' || a[i][nxt_left[i]] == 'W'))
            {
                if (a[i][nxt_left[i]] == 'W')
                {
                    a[i][nxt_left[i]] = '.';
                    ans++;
                }
                nxt_left[i]++;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            while (nxt_up[i] <= nxt_down[i] && (a[nxt_down[i]][i] == '.' || a[nxt_down[i]][i] == 'S'))
            {
                if (a[nxt_down[i]][i] == 'S')
                {
                    a[nxt_down[i]][i] = '.';
                    ans++;
                }
                nxt_down[i]--;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            while (nxt_left[i] <= nxt_right[i] && (a[i][nxt_right[i]] == '.' || a[i][nxt_right[i]] == 'E'))
            {
                if (a[i][nxt_right[i]] == 'E')
                {
                    a[i][nxt_right[i]] = '.';
                    ans++;
                }
                nxt_right[i]--;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            while (nxt_up[i] <= nxt_down[i] && (a[nxt_up[i]][i] == '.' || a[nxt_up[i]][i] == 'N'))
            {
                if (a[nxt_up[i]][i] == 'N')
                {
                    a[nxt_up[i]][i] = '.';
                    ans++;
                }
                nxt_up[i]++;
            }
        }
    }
    // printf("%d\n", ans);
    //in.close();
    return ans;
}

int gen() {
    std::string path = "/home/wolfpro/cod/City 2014/tests/", dpath;
    for (int i = 101; i < 152; ++i ) {
        dpath = path;
        char c = (i / 10) % 10 + '0';
        dpath += c;
        c = i % 10 + '0';
        dpath += c;

        //std::cout << dpath << '\n';
        in.open(dpath);

        clock_t t0 = clock();

        int a1 = my(dpath);

        clock_t t1 = clock();
        std::cout << (double)(t1 - t0) / CLOCKS_PER_SEC * 100 << " ";

        in.close();

        t0 = clock();
        in.open(dpath);
        int a2 =  other(dpath);
        t1 = clock();
        std::cout << (double)(t1 - t0) / CLOCKS_PER_SEC * 10 << " ";

        if (a1 != a2) {
            std::cout << "Fack! " << i - 100 << "\n";
            break;
        } else {
            std::cout << i - 100 << ":OK\n";
        }
    }
    return 0;
}