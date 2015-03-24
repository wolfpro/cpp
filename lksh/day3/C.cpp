#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
struct Node {
    int data;
    Node *next;
};

struct List
{
    Node *head;
    Node *end;
    int size;

    List() {
        size = 0;
        head = NULL;
        end = NULL;
    }

    void print(Node *first)
    {
        if (first == NULL) {
            cout << "Is empty" << endl;
            return;
        }
        for (Node *p = first; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }

    int getOne() {
        if (head == NULL) {
            cout << "Is empty one" << endl;
            return 0;
        }

        Node *p = head;
        int res = p->data;
        head = p->next;
        size--;
        if (p == end)
            end = NULL;
        free(p);
        return res;
    }

    void past(int a, int i)
    {
        if (i > size) {
            cout << "Num is bigger" << endl;
            return;
        }
        int j = 1;
        Node *in = (Node *) calloc(1, 8);
        in->data = a;
        for (Node *p = head; p; p->next, j++) {
            if (i == 0) {
                in->next = head;
                head = in;
                size++;
                return;
            }
            if (i == j) {
                in->next = p->next;
                p->next = in;
                size++;
                return;
            }
        }
    }

    void add(int a)
    {
        if (head == NULL) {
            head  = (Node *) calloc(1, 8);
            head->data = a;
            end = head;
            size = 1;
            return;
        }
        Node *p = end;
        {
            p->next = (Node *)calloc(1, 8);
            p = p->next;
            p->data = a;
            end = p;
        }

        size++;
    }

    void rm(int i)
    {
        if (i >= size) {
            cout << "don't exist element" << endl;
            return;
        }
        int j = 1;
        for (Node *p = head; p; p = p->next, j++) {
            if (i == 0) {
                head = p->next;
                free(p);
                size--;
                return;
            }
            if (i == j) {
                Node *d = p->next;
                p->next = d->next;
                free(d);
                size--;
                return;
            }
        }
    }
};
int main() {
    freopen("card-game.in", "r", stdin);
    freopen("card-game.out", "w", stdout);

    int n;
    cin >> n;
    List l1, l2;

    for (int i = 0, t; i < n / 2; i++) {
        cin >> t;
        l1.add(t);
    }

    for (int i = 0, t; i < n / 2; i++) {
        cin >> t;
        l2.add(t);
    }

    for (int i = 0, a, b; i < 200001; i++) {
        if (l1.size > 0 && l2.size > 0) {
            a = l1.getOne();
            b = l2.getOne();

            if (min(a, b) == 0 && max(a, b) == n - 1) {
                if (a > b) {
                    l2.add(a);
                    l2.add(b);
                    continue;
                } else {
                    l1.add(a);
                    l1.add(b);
                    continue;
                }
            } else {
                if (a > b) {
                    l1.add(a);
                    l1.add(b);
                    continue;
                } else {
                    l2.add(a);
                    l2.add(b);
                    continue;
                }
            }
        } else {
            if (l1.size == 0) {
                cout << "second " << i << endl;
                return 0;
            }
            else {
                cout << "first " << i << endl;
                return 0;
            }
            cout << i << endl;
        }
    }

    cout << "draw" << endl;

    fclose(stdout);
    return 0;
}