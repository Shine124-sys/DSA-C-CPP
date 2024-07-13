#include<iostream>
#include<stack>
#include<string>
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
    if (c == '^' || c == '$')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to check if character is an operand
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert infix expression to postfix expression
void infix_to_prefix(string infix) {
    string prefix;
    for (int i = infix.length() - 1; i >= 0; i--) {
        char symbol = infix[i];
        if (isOperand(symbol)) { // If operand, add to prefix
            prefix = symbol + prefix;
        } else if (symbol == ')') { // If ')' push to stack
            push(symbol);
        } else if (symbol == '(') { // If '(' pop till ')'
            while (!st.empty() && st.top() != ')') {
                prefix = pop() + prefix;
            }
            if (!st.empty() && st.top() == ')')
                pop();
        } else { // If operator, pop to output if precedence is higher
            while (!st.empty() && precedence(st.top()) >= precedence(symbol)) {
                prefix = pop() + prefix;
            }
            push(symbol);
        }
    }
    // Pop all remaining operators in stack
    while (!st.empty()) {
        prefix = pop() + prefix;
    }
    cout << "Equivalent prefix expression is: " << prefix << endl;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    infix_to_prefix(infix);
    return 0;
}
