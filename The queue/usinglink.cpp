/* Program to implement queue using Linked list */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* front = nullptr;
Node* rear = nullptr;

void insert();
void delet();
void display();

int main() {
    int ch;
    while (1) {
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            insert();
            break;
        case 2:
            delet();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Please enter correct choice\n";
        }
    }
    return 0;
}

void insert() {
    Node* ptr = new Node();
    int item;
    cout << "Input the element for inserting: ";
    cin >> item;
    ptr->info = item;
    ptr->link = nullptr;
    if (front == nullptr) // queue is empty
        front = ptr;
    else
        rear->link = ptr;
    rear = ptr;
}

void delet() {
    if (front == nullptr) {
        cout << "Queue is underflow\n";
        return;
    }
    Node* ptr = front;
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->link;
    }
    delete ptr;
}

void display() {
    if (front == nullptr) {
        cout << "Queue is empty\n";
    } else {
        Node* ptr = front;
        cout << "\nElements in the Queue are:\n";
        while (ptr != nullptr) {
            cout << ptr->info << "\n";
            ptr = ptr->link;
        }
        cout << "\n";
    }
}
