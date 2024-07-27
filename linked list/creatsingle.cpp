/* Single linklist */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <limits>

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
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return;
    }

    cout << "Input first node information: ";
    cin >> ptr->info;
    first = ptr;

    do {
        cpt = new Node;
        if (cpt == nullptr) {
            cout << "Memory allocation failed" << endl;
            return;
        }

        cout << "Input next node information: ";
        cin >> cpt->info;
        ptr->link = cpt;
        ptr = cpt;

        cout << "Press 'Y' to add more nodes, 'N' to stop: ";
        cin >> ch;
        // Clear the input buffer to handle any extra newline characters
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (ch == 'Y' || ch == 'y');

    ptr->link = nullptr;
}

int main() {
    create();
    return 0;
}
