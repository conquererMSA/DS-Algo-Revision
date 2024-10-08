#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of elements in the stack
int findSumOfStack(stack<int> s) {
    int total = 0;
    while (!s.empty()) {
        total += s.top();
        s.pop();
    }
    return total;
}

int main() {
    int n1, n2, n3;
    cin >> n1;
    stack<int> s1;
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        s1.push(x);
    }

    cin >> n2;
    stack<int> s2;
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        s2.push(x);
    }

    cin >> n3;
    stack<int> s3;
    for (int i = 0; i < n3; i++) {
        int x;
        cin >> x;
        s3.push(x);
    }
    int s1Sum = findSumOfStack(s1);
    int s2Sum = findSumOfStack(s2);
    int s3Sum = findSumOfStack(s3);
    while (true) {
        if (s1Sum == s2Sum && s2Sum == s3Sum) break;

        if (s1Sum >= s2Sum && s1Sum >= s3Sum) {
            s1Sum -= s1.top();
            s1.pop();
        } else if (s2Sum >= s1Sum && s2Sum >= s3Sum) {
            s2Sum -= s2.top();
            s2.pop();
        } else {
            s3Sum -= s3.top();
            s3.pop();
        }
    }

    cout << s1Sum << endl;
    return 0;
}
