#include <bits/stdc++.h>
using namespace std;

int main() {
    string parenthesis;
    cin >> parenthesis;
    stack<char> s;

    for (int i = 0; i < parenthesis.size(); i++) {
        char current = parenthesis[i];
        if (!s.empty()) {
            if ((current == ')' && s.top() == '(') ||
                (current == '}' && s.top() == '{') ||
                (current == ']' && s.top() == '[')) {
                s.pop();
            } else {
                s.push(current);
            }
        } else {
            s.push(current);
        }
    }

    if (!s.empty()) {
        cout << "Invalid" << endl;
    } else {
        cout << "Valid" << endl;
    }

    return 0;
}
