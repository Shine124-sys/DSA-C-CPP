#include <iostream>
using namespace std;

struct node {
    int info;
    struct node *link;
};
struct node *top;

void create();
void traverse();
void push();
void pop();

int main() {
    create();
    cout << "\nStack is:\n";
    traverse();
    push();
    cout << "\nAfter pushing an element, the stack is:\n";
    traverse();
    pop();
    cout << "\nAfter popping an element, the stack is:\n";
    traverse();
    return 0;
}

void create() {
    struct node *ptr, *cpt;
    char ch;
    ptr = new node;
    cout << "Input first info: ";
    cin >> ptr->info;
    ptr->link = NULL;
    do {
        cpt = new node;
        cout << "\nInput next information: ";
        cin >> cpt->info;
        cpt->link = ptr;
        ptr = cpt;
        cout << "Press <Y/N> for more information: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    top = ptr;
}

void traverse() {
    struct node *ptr;
    cout << "Traversing of stack:\n";
    ptr = top;
    while (ptr != NULL) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

void push() {
    struct node *ptr;
    ptr = new node;
    if (ptr == NULL) {
        cout << "Overflow\n";
        return;
    }
    cout << "Input New node information: ";
    cin >> ptr->info;
    ptr->link = top;
    top = ptr;
}

void pop() {
    struct node *ptr;
    if (top == NULL) {
        cout << "Underflow\n";
        return;
    }
    ptr = top;
    top = ptr->link;
    delete ptr;
}
