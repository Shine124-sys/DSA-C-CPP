/* Insertion after given node in single linklist*/
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
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

void insert_given_node() {
    Node* ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input new node information: ";
    cin >> ptr->info;

    int data;
    cout << "Input information of node after which insertion will be made: ";
    cin >> data;

    Node* cpt = first;
    while (cpt != nullptr && cpt->info != data) {
        cpt = cpt->link;
    }

    if (cpt == nullptr) {
        cout << "Node with data " << data << " not found.\n";
        delete ptr;
        return;
    }

    ptr->link = cpt->link;
    cpt->link = ptr;
}

int main() {
    create();
    traverse();
    insert_given_node();
    traverse();
    return 0;
}
