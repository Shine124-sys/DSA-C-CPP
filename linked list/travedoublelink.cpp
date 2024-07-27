/* Traversing in Double linklist*/
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* lpt;
    Node* rpt;
};

Node* first = nullptr;

void create() {
    Node* ptr = nullptr;
    Node* cpt = nullptr;
    char ch;

    // Create the first node
    ptr = new Node;
    if (!ptr) {
        cerr << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input first node information: ";
    cin >> ptr->info;
    ptr->lpt = nullptr;
    first = ptr;

    do {
        // Create subsequent nodes
        cpt = new Node;
        if (!cpt) {
            cerr << "Memory allocation failed" << endl;
            return;
        }

        cout << "Input next node information: ";
        cin >> cpt->info;
        ptr->rpt = cpt;
        cpt->lpt = ptr;
        ptr = cpt;

        cout << "Press 'Y' for more nodes, 'N' to stop: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    
    ptr->rpt = nullptr;
}

void ftraverse() {
    Node* ptr = first;
    cout << "Forward Traversing:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->rpt;
    }
}

void btraverse() {
    Node* ptr = first;

    // Move to the end of the list
    while (ptr && ptr->rpt != nullptr) {
        ptr = ptr->rpt;
    }

    cout << "\nBackward Traversing:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->lpt;
    }
}

int main() {
    create();
    btraverse();
    ftraverse();
    return 0;
}
