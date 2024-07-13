
/* IMPLEMENT HEAP SORT USING ARRAYS */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

int a[20], n;

void display() {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void insert(int num, int loc) {
    int parent;
    while (loc > 0) {
        parent = (loc - 1) / 2;
        if (num <= a[parent]) {
            a[loc] = num;
            return;
        }
        a[loc] = a[parent];
        loc = parent;
    }
    a[0] = num;
}

void create_heap() {
    for (int i = 0; i < n; i++)
        insert(a[i], i);
}

void del_root(int last) {
    int left, right, i, temp;
    i = 0;
    temp = a[i];
    a[i] = a[last];
    a[last] = temp;
    left = 2 * i + 1;
    right = 2 * i + 2;
    while (right < last) {
        if (a[i] >= a[left] && a[i] >= a[right])
            return;
        if (a[right] <= a[left]) {
            temp = a[i];
            a[i] = a[left];
            a[left] = temp;
            i = left;
        } else {
            temp = a[i];
            a[i] = a[right];
            a[right] = temp;
            i = right;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    if (left == last - 1 && a[i] < a[left]) {
        temp = a[i];
        a[i] = a[left];
        a[left] = temp;
    }
}

void heap_sort() {
    for (int last = n - 1; last > 0; last--)
        del_root(last);
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }
    
    cout << "\nEntered list is:\n";
    display();
    
    create_heap();
    cout << "\nHeap is:\n";
    display();
    
    heap_sort();
    cout << "\nSorted list is:\n";
    display();
    
    return 0;
}
