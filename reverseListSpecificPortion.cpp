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
    auto endInIt=l.begin();
    for(int i=0; i<4 && endInIt!=l.end(); i++) endInIt++;
    reverse(l.begin(), endInIt);
    for(int val:l) cout<<val<<" ";
    /*
    8
    1 4 7 3 9 3 0 2
    output: 3 7 4 1 9 3 0 2 
    */
    return 0;
}