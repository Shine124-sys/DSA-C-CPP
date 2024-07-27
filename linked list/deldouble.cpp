/* Deletion in Doubly linklist */
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

    cout << "\nInput first node information: ";
    cin >> ptr->info;
    ptr->lpt = nullptr;
    first = ptr;

    do {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return;
        }

        cout << "\nInput next node information: ";
        cin >> cpt->info;
        ptr->rpt = cpt;
        cpt->lpt = ptr;
        ptr = cpt;

        cout << "Press 'Y' to add more nodes, 'N' to stop: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    } while (ch == 'Y' || ch == 'y');

    ptr->rpt = nullptr;
}

void ftraverse() {
    Node *ptr = first;
    cout << "Traversing the linked list:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->rpt;
    }
}

void delete_beg() {
    if (first == nullptr) {
        cout << "Underflow: The list is empty" << endl;
        return;
    }

    Node *ptr = first;
    first = ptr->rpt;
    if (first != nullptr) {
        first->lpt = nullptr;
    }
    delete ptr; // Use delete instead of free in C++
    cout << "Deletion at beginning done" << endl;
}

void delete_end() {
    if (first == nullptr) {
        cout << "Underflow: The list is empty" << endl;
        return;
    }

    Node *ptr = first;
    Node *cpt = nullptr;
    while (ptr->rpt != nullptr) {
        cpt = ptr;
        ptr = ptr->rpt;
    }

    if (cpt != nullptr) {
        cpt->rpt = nullptr;
    } else {
        first = nullptr;
    }
    delete ptr; // Use delete instead of free in C++
    cout << "Deletion at end done" << endl;
}

void delete_given_node() {
    if (first == nullptr) {
        cout << "Underflow: The list is empty" << endl;
        return;
    }

    int m;
    cout << "\nNode to be deleted: ";
    cin >> m;

    Node *ptr = first;
    while (ptr != nullptr && ptr->info != m) {
        ptr = ptr->rpt;
    }

    if (ptr == nullptr) {
        cout << "Node not found" << endl;
        return;
    }

    Node *cpt = ptr->lpt;
    Node *tpt = ptr->rpt;

    if (cpt != nullptr) {
        cpt->rpt = tpt;
    } else {
        first = tpt;
    }

    if (tpt != nullptr) {
        tpt->lpt = cpt;
    }

    delete ptr; // Use delete instead of free in C++
    cout << "Deletion of given node done" << endl;
}

int main() {
    create();
    ftraverse();
    delete_beg();
    cout << "\nDoubly linked list after deletion at beginning:\n";
    ftraverse();
    delete_end();
    cout << "\nDoubly linked list after deletion at end:\n";
    ftraverse();
    delete_given_node();
    cout << "\nDoubly linked list after deletion of a given node:\n";
    ftraverse();
    return 0;
}
