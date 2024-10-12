#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int, greater<int>> s = {1, 2, 3, 4, 5};
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
