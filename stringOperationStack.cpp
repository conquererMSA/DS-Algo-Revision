#include <bits/stdc++.h>
using namespace std;

int main() {
    string operations;
    cin >> operations;
    stack<int> st;

    for (char s : operations) {
        if (s == '+') {
            if (st.size() >= 2) {
                int prev1 = st.top();
                st.pop();
                int prev2 = st.top();
                st.push(prev1);
                st.push(prev1 + prev2);
            }
        } else if (s == 'D') {
            if (!st.empty()) {
                st.push(st.top() * 2);
            }
        } else if (s == 'C') {
            if (!st.empty()) {
                st.pop();
            }
        } else if (isdigit(s)) {
            st.push(s - '0'); // Convert char digit to int
        }
    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;

    return 0;
}
