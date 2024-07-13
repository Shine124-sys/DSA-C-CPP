/* Implementation of Binary Search */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

int main() {
    char ch;
    int arr[20], start, end, mid, n, i, data;

    cout << "\nHow many elements you want to enter in the array: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\nEnter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\n\nPress any key to continue...";

    do {
        cout << "\nEnter the element to be searched: ";
        cin >> data;

        start = 0;
        end = n - 1;
        mid = (start + end) / 2;

        while (data != arr[mid] && start <= end) {
            if (data > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
            mid = (start + end) / 2;
        }

        if (data == arr[mid])
            cout << "\n" << data << " found at position " << mid + 1 << endl;
        if (start > end)
            cout << "\n" << data << " not found in array\n";

        cout << "\n\n Press <Y or y> to continue: ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
