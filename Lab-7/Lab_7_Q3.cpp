#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
string infixToPostfix(string exp) {
    stack<char> st;
    string postfix;
    for (char c : exp) {
        if (isspace((unsigned char)c)) continue;
        if (isalnum((unsigned char)c)) postfix += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(c) ||
                  (precedence(st.top()) == precedence(c) && c != '^'))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        if (st.top() != '(') postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string exp = "A+B*(C^D-E)^(F+G*H)-I";
    cout << "Postfix expression = " << infixToPostfix(exp) << '\n';
    return 0;
}
