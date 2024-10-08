#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st;
    stack<int> minSt;

    while (n--) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int num;
            cin >> num;
            st.push(num);
            if (minSt.empty() || num <= minSt.top()) {
                minSt.push(num);
            }
        } else if (operation == 2) {
            if (!st.empty()) {
                if (st.top() == minSt.top()) {
                    minSt.pop();
                }
                st.pop();
            }
        } else if (operation == 3) {
            if (!st.empty()) {
                cout << st.top() << endl;
            } else {
                cout << -1 << endl;
            }
        } else if (operation == 4) {
            if (!minSt.empty()) {
                cout << minSt.top() << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
