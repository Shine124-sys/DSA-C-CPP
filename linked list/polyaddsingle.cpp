/* Polynomial addition in single linklist*/
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>

using namespace std;

struct Node {
    int coff;
    int expo;
    Node* link;
};

Node* create(Node* first) {
    Node* ptr;
    Node* cpt;
    char ch;

    ptr = new Node;
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return first;
    }

    cout << "Input first term coefficient and exponent: ";
    cin >> ptr->coff >> ptr->expo;
    ptr->link = nullptr;
    first = ptr;

    do {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return first;
        }

        cout << "Input next term coefficient and exponent: ";
        cin >> cpt->coff >> cpt->expo;
        cpt->link = nullptr;
        ptr->link = cpt;
        ptr = cpt;

        cout << "Press 'Y' for more nodes, 'N' to stop: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    
    return first;
}

void traverse(Node* first) {
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

Node* addition_poly(Node* first1, Node* first2) {
    Node* ptr1 = first1;
    Node* ptr2 = first2;
    Node* first3 = nullptr;
    Node* ptr = nullptr;
    Node* cpt = nullptr;

    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->expo > ptr2->expo) {
            cpt = new Node;
            if (cpt == nullptr) {
                cout << "Memory allocation failed" << endl;
                return first3;
            }
            cpt->coff = ptr1->coff;
            cpt->expo = ptr1->expo;
            ptr1 = ptr1->link;
        } else if (ptr2->expo > ptr1->expo) {
            cpt = new Node;
            if (cpt == nullptr) {
                cout << "Memory allocation failed" << endl;
                return first3;
            }
            cpt->coff = ptr2->coff;
            cpt->expo = ptr2->expo;
            ptr2 = ptr2->link;
        } else {
            cpt = new Node;
            if (cpt == nullptr) {
                cout << "Memory allocation failed" << endl;
                return first3;
            }
            cpt->coff = ptr1->coff + ptr2->coff;
            cpt->expo = ptr1->expo;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        
        cpt->link = nullptr;
        if (first3 == nullptr) {
            first3 = cpt;
            ptr = first3;
        } else {
            ptr->link = cpt;
            ptr = cpt;
        }
    }

    while (ptr1 != nullptr) {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return first3;
        }
        cpt->coff = ptr1->coff;
        cpt->expo = ptr1->expo;
        cpt->link = nullptr;
        ptr->link = cpt;
        ptr = cpt;
        ptr1 = ptr1->link;
    }

    while (ptr2 != nullptr) {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return first3;
        }
        cpt->coff = ptr2->coff;
        cpt->expo = ptr2->expo;
        cpt->link = nullptr;
        ptr->link = cpt;
        ptr = cpt;
        ptr2 = ptr2->link;
    }

    return first3;
}

int main() {
    Node* p1_start = nullptr;
    Node* p2_start = nullptr;
    Node* p3_start = nullptr;

    cout << "Polynomial 1:\n";
    p1_start = create(p1_start);

    cout << "Polynomial 2:\n";
    p2_start = create(p2_start);

    p3_start = addition_poly(p1_start, p2_start);

    cout << "Polynomial 1 is: ";
    traverse(p1_start);
    cout << "Polynomial 2 is: ";
    traverse(p2_start);
    cout << "Added polynomial is: ";
    traverse(p3_start);

    return 0;
}
