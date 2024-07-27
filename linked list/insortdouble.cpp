/* Insertion in sorted doubly linklist*/
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

        cout << "Input next node in increasing order: ";
        cin >> cpt->info;
        cpt->rpt = nullptr;
        cpt->lpt = ptr;
        ptr->rpt = cpt;
        ptr = cpt;

        cout << "Press 'Y' for more nodes, 'N' to stop: ";
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

void insert_sorted() {
    Node *ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input new node information: ";
    cin >> ptr->info;

    Node *cpt = first;
    Node *tpt = nullptr;

    // Traverse to find the correct position for insertion
    while (cpt != nullptr && cpt->info < ptr->info) {
        tpt = cpt;
        cpt = cpt->rpt;
    }

    if (tpt == nullptr) { // Insert at the beginning
        ptr->rpt = first;
        ptr->lpt = nullptr;
        if (first != nullptr) {
            first->lpt = ptr;
        }
        first = ptr;
    } else { // Insert in the middle or at the end
        tpt->rpt = ptr;
        ptr->lpt = tpt;
        ptr->rpt = cpt;
        if (cpt != nullptr) {
            cpt->lpt = ptr;
        }
    }

    cout << "Insertion is done\n";
}

int main() {
    create();
    ftraverse();
    insert_sorted();
    cout << "\nDoubly linked list after insertion is:\n";
    ftraverse();
    return 0;
}
