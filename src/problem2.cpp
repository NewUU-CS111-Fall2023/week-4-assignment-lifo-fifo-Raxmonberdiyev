
/*
 * Author: Raximberdi
 * Date: 11.07.2023
 * Name: Task 2
 */


#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool isValidExpression(const string& brackets) {
    stack<char> st;

    for (char bracket : brackets) {
        if (bracket == '('  bracket == '['  bracket == '{') {
            st.push(bracket);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            if ((bracket == ')' && top == '(')
                    (bracket == ']' && top == '[')
                    (bracket == '}' && top == '{')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    int n;
    cin >> n;

    string brackets;
    cin >> brackets;

    if (!isValidExpression(brackets)) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> trainOrder(n);
    for (int i = 0; i < n; i++) {
        cin >> trainOrder[i];
    }

    stack<int> station;
    vector<int> output;

    for (int i = 0; i < n; i++) {
        station.push(trainOrder[i]);
        output.push_back(1);
        while (!station.empty() && station.top() == output.size()) {
            station.pop();
            output.push_back(2);
        }
    }

    if (station.empty()) {
        for (int action : output) {
            cout << action << " ";
        }
        cout << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}