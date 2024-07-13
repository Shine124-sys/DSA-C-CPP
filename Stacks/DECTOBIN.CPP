#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stk;
    int dec, rem;

    cout << "Enter decimal number: ";
    cin >> dec;

    while (dec != 0) {
        rem = dec % 2;
        stk.push(rem);
        dec = dec / 2;
    }

    cout << "The equivalent binary number is: ";
    while (!stk.empty()) {
        cout << stk.top();
        stk.pop();
    }
    cout << endl;

    return 0;
}
