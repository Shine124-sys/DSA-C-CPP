/* IMPLEMENT MERGE SORT WITHOUT RECURSION */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

#define MAX 20

int main() {
    int a[MAX], temp[MAX], i, j, k, n, size, l1, h1, l2, h2;

    cout << "Enter the number of elements: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "\nUnsorted list is:";
    for (i = 0; i < n; i++)
        cout << " " << a[i];
    
    for (size = 1; size < n; size = size * 2) {
        l1 = 0;
        k = 0; // Index for temp array

        while (l1 + size < n) {
            h1 = l1 + size - 1;
            l2 = h1 + 1;
            h2 = l2 + size - 1;

            if (h2 >= n)
                h2 = n - 1;

            // Merge the two pairs with lower limits l1 and l2
            i = l1;
            j = l2;

            while (i <= h1 && j <= h2) {
                if (a[i] <= a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            while (i <= h1)
                temp[k++] = a[i++];
            
            while (j <= h2)
                temp[k++] = a[j++];

            l1 = h2 + 1; // Take the next two pairs for merging
        }

        for (i = l1; k < n; i++) // Any pair left
            temp[k++] = a[i];

        for (i = 0; i < n; i++)
            a[i] = temp[i];

        cout << "\nSize=" << size << "\nElements are : ";
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
    }

    cout << "\nSorted list is:\n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}
