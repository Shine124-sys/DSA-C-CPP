/* Program to implement queue using array */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#define MAX 100

using namespace std;

int q[MAX + 1], front = 0, rear = 0;

void create();
void traverse();
void insert();
void delet();

int main() {
    create();
    traverse();
    insert();
    cout << "\nAfter inserting an element";
    traverse();
    delet();
    cout << "\nAfter deletion";
    traverse();
    return 0;
}

void create() {
    char ch;
    front = 1;
    do {
        rear++;
        cout << "\nInput element in queue: ";
        cin >> q[rear];
        cout << "Press <Y/N> for more elements: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void traverse() {
    cout << "\nElements in the Queue are:\n";
    for (int i = front; i <= rear; ++i)
        cout << q[i] << endl;
}

void insert() {
    if (rear == MAX) {
        cout << "Queue is overflow\n";
        return;
    }
    int m;
    cout << "\nInput new element to insert: ";
    cin >> m;
    rear++;
    q[rear] = m;
}

void delet() {
    if (front == 0) {
        cout << "Queue is underflow\n";
        return;
    }
    if (front == rear) {
        q[front] = '\0';
        front = rear = 0;
    } else {
        q[front] = '\0';
        front++;
    }
}
