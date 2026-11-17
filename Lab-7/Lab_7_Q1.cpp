#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int best = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            st.pop();
            if (st.empty()) st.push(i);
            else best = max(best, i - st.top());
        }
    }
    return best;
}
int main() {
    string s = ")()())";
    cout << "Longest valid parentheses length = "
         << longestValidParentheses(s) << '\n';
    return 0;
}
