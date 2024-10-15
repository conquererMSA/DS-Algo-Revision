#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    set<int> balls;
    for(int i=0; i<n; i++){
       int x;
       cin>>x;
       balls.insert(x);
    }
    int ans=0;
    for(auto it=balls.begin(); it!=balls.end(); it++){
         ans+=*it;
    }
    cout<<ans<<endl;
    return 0;
}