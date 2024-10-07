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
    list<int> m(l);
    m.reverse();
    if(m==l) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}