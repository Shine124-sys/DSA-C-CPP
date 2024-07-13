/* Circular queue using array */
/* Data Structures Using C++ by Shoriful Shine */

#include <iostream>
#include <cstdlib>
#define MAX 5

using namespace std;

int cqueue[MAX];
int front = -1;
int rear = -1;

void insert();
void del();
void display();
int select();

int main() {
    int choice;
    while (1) {
        choice = select();
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

int select() {
    int choice;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Display" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        cout << "Queue is Overflow" << endl;
        return;
    }
    if (front == -1) { /*If queue is empty*/
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) { /*rear is at last position of queue*/
        rear = 0;
    } else {
        rear = rear + 1;
    }
    cout << "Input the element for insertion: ";
    cin >> item;
    cqueue[rear] = item;
}

void del() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "Deleted element from queue is: " << cqueue[front] << endl;
    if (front == rear) { /* queue has only one element */
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

void display() {
    int front_pos = front, rear_pos = rear;
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: " << endl;
    if (front_pos <= rear_pos) {
        while (front_pos <= rear_pos) {
            cout << cqueue[front_pos] << " ";
            front_pos++;
        }
    } else {
        while (front_pos <= MAX - 1) {
            cout << cqueue[front_pos] << " ";
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos) {
            cout << cqueue[front_pos] << " ";
            front_pos++;
        }
    }
    cout << endl;
}
