/* Insertion at end in single linklist*/
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* first = nullptr;

void create() {
    Node* ptr;
    Node* cpt;
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

        cout << "Press 'Y' for more nodes, 'N' to stop: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void traverse() {
    Node* ptr = first;
    cout << "Traversing the linked list:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

void insert_end() {
    Node* ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input new node information: ";
    cin >> ptr->info;
    ptr->link = nullptr;

    if (first == nullptr) {
        first = ptr;
        return;
    }

    Node* cpt = first;
    while (cpt->link != nullptr) {
        cpt = cpt->link;
    }
    cpt->link = ptr;
}

int main() {
    create();
    traverse();
    insert_end();
    traverse();
    return 0;
}
