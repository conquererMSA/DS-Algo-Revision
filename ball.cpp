#include<bits/stdc++.h>
#define ll long long
#define B begin()
#define E end()
#define all(x) x.B,x.E
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(all(vec), greater<>());

    map<int, bool> mp;

    int64_t sum = 0;
    int crr = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (crr > 0) {
            crr = min(crr - 1, vec[i]);
            sum += crr;
        }
    }
    cout << sum << endl;
}
int main()
{
    fast();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}