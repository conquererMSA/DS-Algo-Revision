#include <bits/stdc++.h>
using namespace std;
/*
7
-7 1 5 2 -4 3 0
output: 3
*/
int findEquilibriumIndex(const vector<int>& arr) {
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }
    
    int left_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        int right_sum = total_sum - left_sum - arr[i];
        
        if (left_sum == right_sum) {
            return i;
        }
        left_sum += arr[i];
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int equilibriumIndex = findEquilibriumIndex(arr);
    if (equilibriumIndex != -1) {
        cout<< equilibriumIndex << endl;
    } else {
        cout<<"Not Found"<<endl;
    }
    
    return 0;
}
