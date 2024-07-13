/* Operations performed on the stack */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

#define maxsize 30
int stack[maxsize], top = -1;

void push();
void pop();
void display();

int main() {
    int ch = 1;
    while (ch) {
        cout << "\n1 Push";
        cout << "\n2 Pop";
        cout << "\n3 Display";
        cout << "\n4 Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                cout << "\nInvalid choice\n";
                break;
        }
    }
    return 0;
}

void push() {
    int no;
    if (top == maxsize - 1) {
        cout << "\nStack overflow\n";
        return;
    }
    top++;
    cout << "\nEnter number: ";
    cin >> no;
    stack[top] = no;
    cout << "\nElements in stack are:\n";
    display();
}

void pop() {
    if (top == -1) {
        cout << "\nStack underflow\n";
        return;
    } else {
        top--;
        cout << "\nElements in stack are:\n";
        display();
    }
}

void display() {
    if (top == -1) {
        cout << "\nStack is empty\n";
        return;
    }
    cout << "\nStack elements:\n";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}
