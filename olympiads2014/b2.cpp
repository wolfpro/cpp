#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 300001;
const int MAGIC = 4;

struct elem {
    int t1, t2, t3, t4;
    elem(int _t1 = -1, int _t2 = -1, int _t3 = -1, int _t4 = -1) {
        t1 = _t1, t2 = _t2, t3 = _t3, t4 = _t4;
    }
    void update(int _t1 = -1, int _t2 = -1, int _t3 = -1, int _t4 = -1) {
        t1 = _t1, t2 = _t2, t3 = _t3, t4 = _t4;
    }
    void print() {
        int c = (t1 != -1) + (t2 != -1) + (t3 != -1) + (t4 != -1);
        std::cout << c << "\n";
        if (t1 != -1)
            std::cout << t1 + 1 << " ";
        if (t2 != -1)
            std::cout << t2 + 1 << " ";
        if (t3 != -1)
            std::cout << t3 + 1 << " ";
        if (t4 != -1)
            std::cout << t4 + 1 << " ";
        std::cout << "\n";
    }
};

int V, E;
int x, y;
int b[MAXN], d[MAXN];
std::pair<int, int> e[MAXN];

std::vector<std::pair <int, int> > g[MAXN];

int best, cur, cur2, cur3;
elem res;

void go(int x, int y) {
    cur = b[x] + b[y];
    if (cur > best) {
        best = cur;
        res.update(x, y);
    }
    for (int j = 0; j < d[x]; ++j) {
        int bx = g[x][j].second;
        if (bx == y)
            continue;
        cur2 = cur + b[bx];
        if (cur2 > best) {
            best = cur2;
            res.update(bx, x, y);
        }
        for (int k = 0; k < d[y]; ++k) {
            int by = g[y][k].second;
            if (by == x || by == bx)
                continue;
            cur3 = cur2 + b[by];
            if (cur3 > best) {
                best = cur3;
                res.update(bx, x, y, by);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    std::cin >> V >> E;
    for (int i = 0; i < V; ++i) {
        std::cin >> b[i];
        if (b[i] > best) {
            best = b[i];
            res.update(i);
        }
    }

    for (int i = 0; i < E; ++i) {
        std::cin >> x >> y;
        x--, y--;
        e[i].first = x, e[i].second = y;
        g[x].push_back(std::make_pair(b[y], y));
        g[y].push_back(std::make_pair(b[x], x));
    }

    for (int i = 0; i < V; ++i) {
        std::sort(g[i].rbegin(), g[i].rend());
        d[i] = std::min((int)g[i].size(), MAGIC);
    }

    for (int i = 0; i < E; ++i) {
        x = e[i].first, y = e[i].second;
        go(x, y);
        std::swap(x, y);
        go(x, y);
    }

    res.print();

    return 0;
}