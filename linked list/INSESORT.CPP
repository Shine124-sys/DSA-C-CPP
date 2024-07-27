/* Insertion in sorted single linked list */
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
    cout << "Traversing the linked list:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

void insert_sorted_link() {
    Node *ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input new node information: ";
    cin >> ptr->info;

    Node *cpt = first;
    Node *tpt = nullptr;

    // Insert at the beginning or find the correct position
    while (cpt != nullptr && cpt->info < ptr->info) {
        tpt = cpt;
        cpt = cpt->link;
    }

    if (tpt == nullptr) { // Insert at the beginning
        ptr->link = first;
        first = ptr;
    } else { // Insert in the middle or at the end
        tpt->link = ptr;
        ptr->link = cpt;
    }

    cout << "Node inserted in sorted order" << endl;
}

int main() {
    create();
    traverse();
    insert_sorted_link();
    traverse();
    return 0;
}
