/* Traversing of single linklist */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>

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
    cout << "Input first node information: ";
    cin >> ptr->info;
    first = ptr;
    
    do {
        cpt = new Node;
        cout << "Input next node information: ";
        cin >> cpt->info;
        ptr->link = cpt;
        ptr = cpt;
        
        cout << "Press 'Y' to add more nodes, 'N' to stop: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    
    ptr->link = nullptr;
}

void traverse() {
    Node *ptr = first;
    cout << "Traversing the linked list:" << endl;
    while (ptr != nullptr) {
        cout << ptr->info << endl;
        ptr = ptr->link;
    }
}

int main() {
    create();
    traverse();
    return 0;
}
