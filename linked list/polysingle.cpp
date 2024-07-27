/* creation of polynomial*/
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>

using namespace std;

struct Node {
    int coff;
    int expo;
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

    cout << "Input first term coefficient and exponent: ";
    cin >> ptr->coff >> ptr->expo;
    ptr->link = nullptr;
    first = ptr;

    do {
        // Creating subsequent nodes
        cpt = new Node;
        if (cpt == nullptr) {
            cerr << "Memory allocation failed" << endl;
            return;
        }

        cout << "Input next term coefficient and exponent: ";
        cin >> cpt->coff >> cpt->expo;
        cpt->link = nullptr;
        ptr->link = cpt;
        ptr = cpt;

        cout << "Press 'Y' for more nodes, 'N' to stop: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}

void traverse() {
    Node* ptr = first;
    cout << "Terms of polynomials are: ";
    while (ptr != nullptr) {
        cout << ptr->coff << " X^" << ptr->expo;
        if (ptr->link != nullptr) {
            cout << " + ";
        }
        ptr = ptr->link;
    }
    cout << endl;
}

int main() {
    create();
    traverse();
    return 0;
}
