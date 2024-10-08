#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    cin >> word;
    stack<char> charSt;
    for (char c : word) {
        if (!charSt.empty() && charSt.top() == c) {
            charSt.pop();
        } else {
            charSt.push(c); 
        }
    }
    string s = "";
    while (!charSt.empty()) {
        s += charSt.top();
        charSt.pop(); 
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    
    return 0;
}
