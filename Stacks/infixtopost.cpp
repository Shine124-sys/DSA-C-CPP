#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

// Function to push operators and parenthesis onto the stack
void push(char c) {
    st.push(c);
}

// Function to pop from stack
char pop() {
    char c = st.top();
    st.pop();
    return c;
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix expression
void infix_to_postfix(string infix) {
    string postfix;
    for (char c : infix) {
        if (isalnum(c)) { // If operand, add to postfix
            postfix += c;
        } else if (c == '(') { // If '(' push to stack
            push(c);
        } else if (c == ')') { // If ')' pop till '('
            while (!st.empty() && st.top() != '(') {
                postfix += pop();
            }
            if (!st.empty() && st.top() == '(')
                pop();
        } else { // If operator, pop to output if precedence is higher
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += pop();
            }
            push(c);
        }
    }
    // Pop all remaining operators in stack
    while (!st.empty()) {
        postfix += pop();
    }
    cout << "Equivalent postfix expression is: " << postfix << endl;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    infix_to_postfix(infix);
    return 0;
}
