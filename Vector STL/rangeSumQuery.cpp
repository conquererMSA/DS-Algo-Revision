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
    vector<int> prefixSum(n);
    prefixSum[0]=v[0];
    for(int i=1; i<n; i++){
        prefixSum[i]=prefixSum[i-1]+v[i];
    }
    while (q--) {
        int l,r;
        cin >>l>>r;
        int lIn=l-1, rIn=r-1;
        if(lIn==0) cout<<prefixSum[rIn]<<endl;
        else cout<<prefixSum[rIn]-prefixSum[lIn-1]<<endl;
    }
    return 0;
}
