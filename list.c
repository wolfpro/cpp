#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;
int size = 0;

void print(Node *first)
{
    if (first == NULL) {
        cout << "Is empty" << endl;
        return;
    }
    for (Node *p = first; p; p = p->next)
        cout << p -> data << " ";
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
        if (i == j ) {
            in ->next = p->next;
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
        head -> data = a;
        size = 1;
        return;
    }
    for (Node *p = head; p; p = p->next)
        if (p->next == NULL) {
            p->next = (Node *)calloc(1, 8);
            p = p->next;
            p->data = a;
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
        if (i == j ) {
            Node *d = p -> next;
            p->next = d->next;
            free(d);
            size --;
            return;
        }
    }
}

int main()
{
    //+ a добавить a
    //- i убрать iый
    //? вывести все на экран
    //# i a добавить iым a
    //@ exit
    char c;
    int a, b;
    while (c != '@') {
        cin >> c;

        if (c == '@')
            break;

        if (c != '?')
            cin >> a;

        if (c == '+')
            add(a);
        if (c == '?')
            print(head);
        if (c == '-') {
            rm(a);
        }
        if (c == '#') {
            cin >> b;
            past(a, b);
        }
    }

    return 0;
}