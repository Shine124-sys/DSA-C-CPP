/* Program of priority queue using linked list */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int priority;
    int info;
    Node* link;
} *front = nullptr;

void insert();
void del();
void display();
int select();

int main() {
    int choice;
    while (1) {
        choice = select();
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

int select() {
    int choice;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Display" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void insert() {
    Node* tmp = new Node;
    Node* q;
    int added_item, item_priority;
    cout << "Input the item value to be added in the queue: ";
    cin >> added_item;
    cout << "Enter its priority: ";
    cin >> item_priority;
    tmp->info = added_item;
    tmp->priority = item_priority;

    /* Queue is empty or item to be added has priority
       more than first item */
    if (front == nullptr || item_priority < front->priority) {
        tmp->link = front;
        front = tmp;
    } else {
        q = front;
        while (q->link != nullptr && q->link->priority <= item_priority)
            q = q->link;
        tmp->link = q->link;
        q->link = tmp;
    }
}

void del() {
    Node* tmp;
    if (front == nullptr) {
        cout << "Queue underflow" << endl;
    } else {
        tmp = front;
        cout << "Deleted item is " << tmp->info << endl;
        front = front->link;
        delete tmp;
    }
}

void display() {
    Node* ptr = front;
    if (front == nullptr) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is:" << endl;
        cout << "Priority   Item" << endl;
        while (ptr != nullptr) {
            cout << ptr->priority << "          " << ptr->info << endl;
            ptr = ptr->link;
        }
    }
}
