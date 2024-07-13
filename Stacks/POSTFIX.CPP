/* Program to Evaluate Postfix Notation */
/* Data Structures Using C++ by Shoriful Shine */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string S) {
    stack<int> stack;
    int n = S.length();
    for (int i = 0; i < n; i++) {
        if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/') {
            if (stack.size() < 2) {
                cerr << "Invalid postfix expression: Not enough operands for operation\n";
                return INT_MIN; // Return a special value indicating error
            }
            int y = stack.top(); stack.pop();
            int x = stack.top(); stack.pop();
            switch (S[i]) {
                case '+': stack.push(x + y); break;
                case '-': stack.push(x - y); break;
                case '*': stack.push(x * y); break;
                case '/': 
                    if (y == 0) {
                        cerr << "Invalid postfix expression: Division by zero\n";
                        return INT_MIN; // Return a special value indicating error
                    }
                    stack.push(x / y); 
                    break;
            }
        } else if (isdigit(S[i])) {
            stack.push(S[i] - '0'); // Convert char digit to int
        }
    }
    if (stack.size() != 1) {
        cerr << "Invalid postfix expression: Too many operands\n";
        return INT_MIN; // Return a special value indicating error
    }
    return stack.top();
}

int main() {
    string postfix;
    cout << "Enter a valid postfix expression: ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    if (result != INT_MIN) {
        cout << "The value of the postfix notation is: " << result << endl;
    }

    return 0;
}
