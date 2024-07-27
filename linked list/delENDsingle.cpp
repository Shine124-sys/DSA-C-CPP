/* Deletion at end in Single linklist */
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
    ptr->link = nullptr;
    first = ptr;

    do {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return;
        }

        cout << "Input next node information: ";
        cin >> cpt->info;
        cpt->link = nullptr;
        ptr->link = cpt;
        ptr = cpt;

        cout << "Press 'Y' to add more nodes, 'N' to stop: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    } while (ch == 'Y' || ch == 'y');
}

void traverse() {
    Node *ptr = first;
    cout << "\nTraversing the linked list:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

void delete_end() {
    if (first == nullptr) {
        cout << "Underflow: The list is empty" << endl;
        return;
    }

    Node *ptr = first;
    Node *prev = nullptr;

    // Traverse to the last node
    while (ptr->link != nullptr) {
        prev = ptr;
        ptr = ptr->link;
    }

    // If there is no previous node, it means the list had only one node
    if (prev == nullptr) {
        first = nullptr;
    } else {
        prev->link = nullptr;
    }

    delete ptr; // Use delete instead of free in C++
    cout << "Deletion at end done" << endl;
}

int main() {
    create();
    traverse();
    delete_end();
    cout << "\nAfter deletion of the last node:\n";
    traverse();
    return 0;
}
