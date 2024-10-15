#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> balls(n);

    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }

    sort(balls.rbegin(), balls.rend());

    long long totalBalls = 0;
    int lastUsedCount = INT_MAX;

    for (int count : balls) {
        if (count < lastUsedCount) {
            totalBalls += count; 
            lastUsedCount = count; 
        } else if (lastUsedCount > 0) {
            totalBalls += lastUsedCount; 
            lastUsedCount--; 
        }
    }

    cout << totalBalls << endl;
    return 0;
}
