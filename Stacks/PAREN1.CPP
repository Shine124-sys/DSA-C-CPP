#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_valid_expression(string exp) {
    stack<char> st;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            st.push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (st.empty()) {
                return false;
            } else {
                char top = st.top();
                st.pop();
                if ((exp[i] == ')' && top != '(') ||
                    (exp[i] == '}' && top != '{') ||
                    (exp[i] == ']' && top != '[')) {
                    return false;
                }
            }
        }
    }
    return st.empty();
}

int main() {
    string exp;
    cout << "Enter an algebraic expression: ";
    getline(cin, exp);

    if (is_valid_expression(exp)) {
        cout << "Valid expression\n";
    } else {
        cout << "Invalid expression\n";
    }

    return 0;
}
