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
        int cmd, value;
        cin >> cmd >> value;
        if (cmd == 0) {
            l.push_front(value);
            cout << "L->";
            traversAndChecking("L", l);
            cout << "R->";
            traversAndChecking("R", l);
        } else if (cmd == 1) {
            l.push_back(value);
            cout << "L->";
            traversAndChecking("L", l);
            cout << "R->";
            traversAndChecking("R", l);
        } else if (cmd==2) {
            if(value<0 || value<=l.size()){
            cout << "L->";
            traversAndChecking("L", l);
            cout << "R->";
            traversAndChecking("R", l);
            }
            else {
                auto it=l.begin();
                advance(it,value);
                l.erase(it);
                cout << "L->";
                traversAndChecking("L", l);
                cout << "R->";
                traversAndChecking("R", l);
            }
        }
    }
    return 0;
}
