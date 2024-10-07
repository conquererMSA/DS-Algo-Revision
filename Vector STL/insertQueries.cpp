#include <bits/stdc++.h>
using namespace std;

void traversAndChecking(string type, list<int> &l) {
    if (type == "L") {
        for (auto it = l.begin(); it != l.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        for (auto it = l.rbegin(); it != l.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main() {
    list<int> l;
    int q;
    cin >> q;
    while (q--) {
        int index, val;
        cin >> index >> val;
        if (index == 0) {
            l.push_front(val);
            cout << "L->";
            traversAndChecking("L", l);
            cout << "R->";
            traversAndChecking("R", l);
        } else if (index == l.size()) {
            l.push_back(val);
            cout << "L->";
            traversAndChecking("L", l);
            cout << "R->";
            traversAndChecking("R", l);
        } else if (index > 0 && index < l.size()) {
            auto it = next(l.begin(), index);
            *it = val;
            cout << "L->";
            traversAndChecking("L", l);
            cout << "R->";
            traversAndChecking("R", l);
        } else {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
