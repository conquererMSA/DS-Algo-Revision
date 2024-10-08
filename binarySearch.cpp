#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(), v.end());

    while (q--) {
        int e;
        cin >> e;
        bool ans = false;
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid] == e) {
                ans = true;
                break;
            }
            if (v[mid] > e) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (ans) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
