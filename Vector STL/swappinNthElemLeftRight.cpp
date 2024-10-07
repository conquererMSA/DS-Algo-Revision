#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> l;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        l.push_back(x);
    }

    int position;
    cin >> position;
    int rightIn = l.size() - position;
    auto leftElem = next(l.begin(), position-1);
    auto rightElem = next(l.begin(), rightIn);
    swap(*leftElem, *rightElem);
    for(int val:l) cout<<val<<" ";

    return 0;
}
