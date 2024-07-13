#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node* create();

int main() {
    node *root;
    root = create();

    // Additional code to traverse or manipulate the tree can be added here.

    return 0;
}

node* create() {
    node *temp = new node;
    int data, choice;

    cout << "Press 0 to exit" << endl;
    cout << "Press 1 for new node" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 0) {
        return nullptr;
    } else {
        cout << "Enter value: ";
        cin >> data;
        temp->data = data;
        cout << "Enter the left child of " << data << endl;
        temp->left = create();
        cout << "Enter the right child of " << data << endl;
        temp->right = create();
        return temp;
    }
}
