/* Search an element in single linklist*/
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* first = nullptr;

void create() {
    Node* ptr = nullptr;
    Node* cpt = nullptr;
    char ch;

    // Creating the first node
    ptr = new Node;
    if (ptr == nullptr) {
        cerr << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input first node information: ";
    cin >> ptr->info;
    ptr->link = nullptr;
    first = ptr;

    do {
        // Creating subsequent nodes
        cpt = new Node;
        if (cpt == nullptr) {
            cerr << "Memory allocation failed" << endl;
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
    cout << "\nTraversing the linked list:\n";
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

void search() {
    Node* ptr = first;
    int data;
    cout << "Input information of node to be searched: ";
    cin >> data;
    while (ptr != nullptr) {
        if (ptr->info == data) {
            cout << "Search is successful\n";
            return;
        }
        ptr = ptr->link;
    }
    cout << "This element does not exist\n";
}

int main() {
    create();
    traverse();
    search();
    return 0;
}
