/* Reverse single linklist*/
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

void reverse_list() {
    if (first == nullptr || first->link == nullptr) {
        return; // List is empty or has only one node
    }

    Node* prev = nullptr;
    Node* current = first;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->link; // Store next node
        current->link = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    first = prev; // Update the first node to the new head of the list
}

int main() {
    create();
    traverse();
    reverse_list();
    cout << "Linked list after reversing:\n";
    traverse();
    return 0;
}
