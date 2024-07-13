/* Quick Sort */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

void quicksort(int *, int, int);
int split(int *, int, int);

int a[10] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};

int main() {
    int i;
    
    cout << "\nQuick Sort\n";
    cout << "\nArray before sorting :";
    for(i = 0; i < 10; i++)
        cout << " " << a[i];
    
    quicksort(a, 0, 9);
    
    cout << "\nArray after sorting :";
    for(i = 0; i < 10; i++)
        cout << " " << a[i];
    
    return 0;
}

void quicksort(int a[], int lower, int upper) {
    int i;
    if (upper > lower) {
        i = split(a, lower, upper);
        quicksort(a, lower, i - 1);
        quicksort(a, i + 1, upper);
    }
}

int split(int a[], int lower, int upper) {
    int i, p, q, t;
    p = lower + 1;
    q = upper;
    i = a[lower];
    while (q >= p) {
        while (a[p] < i)
            p++;
        while (a[q] > i)
            q--;
        if (q > p) {
            t = a[p];
            a[p] = a[q];
            a[q] = t;
        }
    }
    t = a[lower];
    a[lower] = a[q];
    a[q] = t;
    return q;
}
