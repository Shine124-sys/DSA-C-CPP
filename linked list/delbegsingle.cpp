/* Deletion from beginning single linklist */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <limits>

using namespace std;

struct Node {
    int info;
    Node *link;
};

Node *first = nullptr;

void create() {
    Node *ptr, *cpt;
    char ch;

    ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input first node information: ";
    cin >> ptr->info;
    first = ptr;

    do {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return;
        }

        cout << "Input next node information: ";
        cin >> cpt->info;
        ptr->link = cpt;
        ptr = cpt;

        cout << "Press 'Y' to add more nodes, 'N' to stop: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    } while (ch == 'Y' || ch == 'y');

    ptr->link = nullptr;
}

void traverse() {
    Node *ptr = first;
    cout << "\nTraversing the linked list:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

void delete_beginning() {
    if (first == nullptr) {
        cout << "Underflow: The list is empty" << endl;
        return;
    }

    Node *ptr = first;
    first = ptr->link;
    delete ptr;  // Use delete instead of free in C++
}

int main() {
    create();
    traverse();
    delete_beginning();
    cout << "\nAfter deletion of the first node:\n";
    traverse();
    return 0;
}
