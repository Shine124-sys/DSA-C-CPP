/* BUBBLE SORT */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
using namespace std;

const int MAXSIZE = 50;

void bubble(int x[], int n) {
    int i, j, tmp;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n - 1; j++) {
            if(x[j] > x[j + 1]) {
                tmp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int x[MAXSIZE], n, i;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "\nEnter the elements: \n";
    for(i = 0; i < n; i++)
        cin >> x[i];
    
    bubble(x, n);
    
    cout << "\nThe sorted output:\n";
    for(i = 0; i < n; i++)
        cout << x[i] << "\n";
    
    return 0;
}
