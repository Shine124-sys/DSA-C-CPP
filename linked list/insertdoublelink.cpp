/* Insertion in doubly linklist*/
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <limits>

using namespace std;

struct Node {
    int info;
    Node *lpt;
    Node *rpt;
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
    ptr->lpt = nullptr;
    ptr->rpt = nullptr;
    first = ptr;

    do {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return;
        }

        cout << "Input next node information: ";
        cin >> cpt->info;
        cpt->lpt = ptr;
        cpt->rpt = nullptr;
        ptr->rpt = cpt;
        ptr = cpt;

        cout << "Press 'Y' to add more nodes, 'N' to stop: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    } while (ch == 'Y' || ch == 'y');
}

void ftraverse() {
    Node *ptr = first;
    cout << "Forward Traversing:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->rpt;
    }
}

void insert_beg() {
    Node *ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input new node information: ";
    cin >> ptr->info;
    ptr->rpt = first;
    ptr->lpt = nullptr;
    if (first != nullptr) {
        first->lpt = ptr;
    }
    first = ptr;
    cout << "New node inserted at the beginning" << endl;
}

void insert_end() {
    Node *ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input new node information: ";
    cin >> ptr->info;
    ptr->rpt = nullptr;

    Node *cpt = first;
    if (cpt == nullptr) {
        // List is empty
        ptr->lpt = nullptr;
        first = ptr;
    } else {
        while (cpt->rpt != nullptr) {
            cpt = cpt->rpt;
        }
        cpt->rpt = ptr;
        ptr->lpt = cpt;
    }

    cout << "Node inserted at the end" << endl;
}

void insert_given_node() {
    Node *ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input new node information: ";
    cin >> ptr->info;

    int m;
    cout << "Input node information after which insertion: ";
    cin >> m;

    Node *cpt = first;
    while (cpt != nullptr && cpt->info != m) {
        cpt = cpt->rpt;
    }

    if (cpt == nullptr) {
        cout << "Node with value " << m << " not found" << endl;
        delete ptr;
        return;
    }

    ptr->rpt = cpt->rpt;
    ptr->lpt = cpt;
    if (cpt->rpt != nullptr) {
        cpt->rpt->lpt = ptr;
    }
    cpt->rpt = ptr;

    cout << "Node inserted after node with value " << m << endl;
}

int main() {
    create();
    ftraverse();
    insert_beg();
    cout << "\nDoubly linked list after insertion at the beginning:\n";
    ftraverse();
    insert_end();
    cout << "\nDoubly linked list after insertion at the end:\n";
    ftraverse();
    insert_given_node();
    cout << "\nDoubly linked list after insertion at a given node:\n";
    ftraverse();
    return 0;
}
