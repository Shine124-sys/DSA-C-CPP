/* Insertion Sort */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

void insertion(int x[], int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        temp = x[i];

        for (j = i - 1; j >= 0; j--) {
            if (temp < x[j])
                x[j + 1] = x[j];
            else
                break;
        }

        x[j + 1] = temp;
    }
}

int main() {
    int x[10], n, i;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "\nEnter the elements: \n";
    for (i = 0; i < n; i++)
        cin >> x[i];

    insertion(x, n);

    cout << "\nThe sorted output:\n";
    for (i = 0; i < n; i++)
        cout << x[i] << "\n";

    return 0;
}
