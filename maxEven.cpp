#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxEven = INT_MIN;
    int largestOdd = INT_MIN, secondLargestOdd = INT_MIN;
    int largestEven = INT_MIN, secondLargestEven = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            if (arr[i] > largestEven) {
                secondLargestEven = largestEven;
                largestEven = arr[i];
            } else if (arr[i] > secondLargestEven) {
                secondLargestEven = arr[i];
            }
            maxEven = max(maxEven, arr[i]);
        } else {
            if (arr[i] > largestOdd) {
                secondLargestOdd = largestOdd;
                largestOdd = arr[i];
            } else if (arr[i] > secondLargestOdd) {
                secondLargestOdd = arr[i];
            }
        }
    }

    if (largestOdd != INT_MIN && secondLargestOdd != INT_MIN) {
        maxEven = max(maxEven, largestOdd + secondLargestOdd);
    }

    if (largestEven != INT_MIN && secondLargestEven != INT_MIN) {
        maxEven = max(maxEven, largestEven + secondLargestEven);
    }

    cout << maxEven << endl;

    return 0;
}
