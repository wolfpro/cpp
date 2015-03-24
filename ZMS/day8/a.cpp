#include <iostream>
#include <vector>
#include <stack>

int mat[101][101], n = 0, m = 0;
bool used[101][101];

struct Pair
{
    int x, y;
};

int main() {
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int t;
            std::cin >> t;
            mat[i][j] = t;
        }


    std::vector < std::vector<int> > v;
    std::stack <Pair> stack;
    Pair p = {0, 0};
    stack.push(p);

    while (stack.size()) {
        p = stack.top();
        stack.pop();

        std::vector<int>  nv;



        for (int i = p.x; i < m; ++i) {
            if (i + 1 >= m || mat[i + 1][p.y] == 1) {
                if (used[i][p.y] == 0) {
                    Pair pp = {i, p.y};
                    stack.push(pp);
                    used[i][p.y] = 1;
                }
            }
        }

        for (int i = p.y; i < n; ++i) {
            if (i + 1 >= n || mat[p.x][i + 1] == 1) {
                if (used[p.x][i] == 0) {
                    Pair pp = {p.x, i};
                    stack.push(pp);
                    used[p.x][i] = 1;
                }
            }
        }

        for (int i = p.x; i > 0; --i) {
            if (i == 0 || mat[i - 1][p.y] == 1) {
                if (used[i][p.y] == 0) {
                    Pair pp = {i, p.y};
                    stack.push(pp);
                    used[i][p.y] = 1;
                }
            }
        }

        for (int i = p.y; i > 0; --i) {
            if (i == 0 || mat[p.x][i - 1] == 1) {
                if (used[p.x][i] == 0) {
                    Pair pp = {p.x, i};
                    stack.push(pp);
                    used[p.x][i] = 1;
                }
            }
        }

    }




    return 0;
}