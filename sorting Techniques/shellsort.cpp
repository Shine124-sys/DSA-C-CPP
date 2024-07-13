/* Shell Sort */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

#define MAX 15

int main() {
    int arr[MAX], i, j, k, n, incr;

    cout << "\nEnter the number of elements: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "\nEnter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nUnsorted list is:\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << "\nEnter maximum increment (odd value): ";
    cin >> incr;

    // Shell sort algorithm is applied
    while (incr >= 1) {
        for (j = incr; j < n; j++) {
            k = arr[j];
            for (i = j - incr; i >= 0 && k < arr[i]; i -= incr)
                arr[i + incr] = arr[i];
            arr[i + incr] = k;
        }
        incr = incr - 2; // Decrease the increment
    }

    cout << "\nSorted list is:\n\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}

