
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfixExpression(const string& expression) {
    stack<int> st;
    for (char c : expression) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else if (c == '+'  c == '-'  c == '*') {
            if (st.size() < 2) {
                cerr << "Invalid postfix expression" << endl;
                return -1;
            }
            int o2 = st.top(); st.pop();
            int o1 = st.top();st.pop();
            if (c == '+') {
                st.push(o1 + o2);
            } else if (c == '-') {
                st.push(o1 - o2);
            } else if (c == '*') {
                st.push(o1 * o2);
            }
        }
    }

    if (st.size() == 1) {
        return st.top();
    } else {
        // Invalid postfix expression
        cerr << "Invalid postfix expression" << endl;
        return -1;
    }
}

int main() {
    string str;
    cin >> str;
    int result = evaluatePostfixExpression(str);
    if (result != -1) {
        cout << "Result: " << result << endl;
    } else {
        cout << "Invalid expression" << endl;
    }
    return 0;
}
