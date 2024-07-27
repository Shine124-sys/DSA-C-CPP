/* Sorting in single linklist*/
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

    // Create the first node
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
        // Create subsequent nodes
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

void sorting() {
    if (first == nullptr) return;  // Empty list

    Node* ptr = nullptr;
    Node* cpt = nullptr;
    int temp;

    for (ptr = first; ptr != nullptr; ptr = ptr->link) {
        for (cpt = ptr->link; cpt != nullptr; cpt = cpt->link) {
            if (ptr->info > cpt->info) {
                temp = ptr->info;
                ptr->info = cpt->info;
                cpt->info = temp;
            }
        }
    }
}

int main() {
    create();
    traverse();
    sorting();
    cout << "\nAfter SORTING:\n";
    traverse();
    return 0;
}
