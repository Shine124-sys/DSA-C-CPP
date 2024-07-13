/* Implementation of Linear Search*/
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

int main() {
    char ch;
    int arr[50], n, i, item;

    cout << "\nHow many elements you want to enter in the array: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\nEnter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\n\nPress any key to continue...";

    do {
        cout << "\nEnter the element to be searched: ";
        cin >> item;

        for (i = 0; i < n; i++) {
            if (item == arr[i]) {
                cout << "\n" << item << " found at position " << i + 1 << endl;
                break;
            }
        }

        if (i == n)
            cout << "\nItem " << item << " not found in array\n";

        cout << "\n\nPress (Y/y) to continue: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
