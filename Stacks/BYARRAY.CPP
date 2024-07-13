#include <iostream>
using namespace std;

#define MAX 50

int stack[MAX + 1];
int top = 0;

void create();
void traverse();
void push();
void pop();

int main() {
    create();
    cout << "\nStack is:\n";
    traverse();
    push();
    cout << "After pushing an element, the stack is:\n";
    traverse();
    pop();
    cout << "After popping an element, the stack is:\n";
    traverse();
    return 0;
}

void create() {
    char ch;
    do {
        top++;
        cout << "Input Element: ";
        cin >> stack[top];
        cout << "Press <Y> for more elements\n";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void traverse() {
    for (int i = top; i > 0; --i)
        cout << stack[i] << endl;
}

void push() {
    int m;
    if (top == MAX) {
        cout << "Stack is overflow" << endl;
        return;
    }
    cout << "Input New Element to Insert: ";
    cin >> m;
    top++;
    stack[top] = m;
}

void pop() {
    if (top == 0) {
        cout << "Stack is underflow" << endl;
        return;
    }
    stack[top] = 0; // Just clearing the top element for demonstration
    top--;
}
