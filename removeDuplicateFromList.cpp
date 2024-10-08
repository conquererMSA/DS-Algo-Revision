#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    list<int> l;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        l.push_back(x);
    }
    l.sort();
    l.unique();
    for(int val:l) cout<<val<<" ";
    return 0;
}