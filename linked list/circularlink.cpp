/* Circular linklist */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* first;

void create() {
    Node* ptr, *cpt;
    char ch;
    ptr = new Node();
    cout << "Input first node: ";
    cin >> ptr->info;
    first = ptr;
    do {
        cpt = new Node();
        cout << "Input next node: ";
        cin >> cpt->info;
        ptr->link = cpt;
        ptr = cpt;
        cout << "Press <Y/N> for more node: ";
        cin >> ch;
    } while (ch == 'Y');
    ptr->link = first;
}

void traverse() {
    Node* ptr;
    cout << "Traversing of link list:\n";
    ptr = first;
    do {
        cout << ptr->info << endl;
        ptr = ptr->link;
    } while (ptr != first);
}

void insert_beg() {
    Node* ptr, *cpt;
    ptr = new Node();
    if (ptr == NULL) {
        cout << "Overflow\n";
        return;
    }
    cout << "Input new node: ";
    cin >> ptr->info;
    cpt = first;
    while (cpt->link != first) {
        cpt = cpt->link;
    }
    ptr->link = first;
    first = ptr;
    cpt->link = first;
}

void insert_end() {
    Node* ptr, *cpt;
    ptr = new Node();
    if (ptr == NULL) {
        cout << "Overflow\n";
        return;
    }
    cout << "Input new node to insert at END: ";
    cin >> ptr->info;
    cpt = first;
    while (cpt->link != first) {
        cpt = cpt->link;
    }
    cpt->link = ptr;
    ptr->link = first;
}

void delete_beg() {
    Node* ptr, *cpt;
    if (first == NULL) {
        cout << "Underflow\n";
        return;
    }
    cpt = first;
    while (cpt->link != first) {
        cpt = cpt->link;
    }
    ptr = first;
    first = ptr->link;
    cpt->link = first;
    delete ptr;
}

void delete_end() {
    Node* ptr, *cpt;
    if (first == NULL) {
        cout << "Underflow\n";
        return;
    }
    cpt = first;
    while (cpt->link != first) {
        ptr = cpt;
        cpt = cpt->link;
    }
    ptr->link = first;
    delete cpt;
}

int main() {
    create();
    cout << "\nCircular linklist is:\n";
    traverse();
    insert_beg();
    cout << "\nCircular linklist after inserting in beginning is:\n";
    traverse();
    insert_end();
    cout << "\nCircular linklist after inserting at end is:\n";
    traverse();
    delete_beg();
    cout << "\nCircular linklist after deleting from beginning is:\n";
    traverse();
    delete_end();
    cout << "\nCircular linklist after deleting from end is:\n";
    traverse();
    return 0;
}