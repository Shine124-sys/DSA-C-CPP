/* Selection Sort */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

#define MAXSIZE 50

void selection(int x[], int n) {
    int i, j, larg, pos, c = 0;
    for (i = n - 1; i > 0; i--) {
        larg = x[0];
        pos = 0;
        for (j = 1; j <= i; j++) {
            c++;
            if (x[j] > larg) {
                larg = x[j];
                pos = j;
            }
        }
        x[pos] = x[i];
        x[i] = larg;
    }
    cout << "\n Number of comparisons required = " << c << endl;
} // end of selection sort

int main() {
    int x[MAXSIZE], n, i;

    cout << "\n Enter number of elements: ";
    cin >> n;

    cout << "\n Unsorted list is as follows:\n";
    for (i = 0; i < n; i++) {
        cout << "\n Enter element " << i + 1 << ": ";
        cin >> x[i];
    }

    selection(x, n);

    cout << "\n Sorted list is:\n\n";
    for (i = 0; i < n; i++)
        cout << x[i] << " ";

    cout << endl;
    return 0;
}

