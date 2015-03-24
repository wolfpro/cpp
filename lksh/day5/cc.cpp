#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

struct Item {
    long long  val, ls, cur;
    std::vector<long long > m;
    std::vector<long long > pos;
};

int cmp(Item a, Item b) {
    return a.cur < b.cur;
}

struct comp {
    bool operator()(const Item a, const Item b) {
        return a.cur < b.cur;
    }
};

int main() {
    freopen("atm.in", "r", stdin);
    freopen("atm.out", "w", stdout);

    long long  n;
    std::cin >> n;

    std::vector<long long > v(n);
    for (long long  i = 0; i < n; ++i)
        std::cin >> v[i];

    std::sort(v.begin(), v.end());
    long long  cost;
    std::cin >> cost;

    std::priority_queue <Item, std::vector <Item>, comp> q;
    std::vector<Item> ans;
    //std::cout << "ok\n";
    for (long long  i = 0; i < n; ++i) {
        Item t;
        t.val = cost % v[i];
        t.m.push_back(v[i]);
        t.ls = i;

        t.pos.push_back(cost / v[i]);
        //std::cout << t.pos[t.pos.size() - 1] << '\n';

        t.cur = cost / v[i];

        // std::cout << t.val << ":" << t.cur << '\n';
        if (t.val == 0) {
            //std::cout << tp.cur << '\n';
            ans.push_back(t);
        } else
            q.push(t);
    }
    //std::cout << '\n';
    //std::cout << "ok\n";

    while (!q.empty()) {
        Item t = q.top();
        q.pop();
        Item tp;
        for (long long  i = 0; i < t.ls && v[i] <= t.val;  ++i) {
            //std::cout << tp.val << '\n';
            tp.val = t.val % v[i];
            t.m.push_back(v[i]);
            tp.m = t.m;
            t.m.resize(t.m.size() - 1);
            tp.ls = i;

            t.pos.push_back(t.val / v[i]);
            tp.pos = t.pos;
            t.pos.resize(t.pos.size() - 1);

            tp.cur = t.cur + (t.val / v[i]);

            if (tp.val == 0) {
                //std::cout << tp.cur << '\n';
                ans.push_back(tp);
            } else
                q.push(tp);
        }
        // std::cout << q.size() << '\n';
    }
    std::sort(ans.begin(), ans.end(), cmp);

    if (ans.size() == 0)
        std::cout << "-1\n";
    else {
        std::cout <<  ans[0].cur << "\n";
        for (long long  i = 0; i < ans[0].m.size(); ++i)
            for (long long  j = 0; j < ans[0].pos[i]; ++j) {
                std::cout << ans[0].m[i] << " ";
            }
        std::cout << '\n';
    }

    fclose(stdout);

    return 0;
}