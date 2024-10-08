#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> logs;
    string input;
    getline(cin, input); 
    //d1/ x12/ ../ ./ ez/
    //2
    stringstream ss(input);
    string log;
    while (ss >> log) {
        logs.push_back(log);
    }

    stack<string> st;
    for (string log : logs) {
        if (log == "../") {
            if (!st.empty()) st.pop();
        } else if (log == "./") {
            continue;
        } else {
            st.push(log);
        }
    }

    cout << st.size() << endl;
    return 0;
}
