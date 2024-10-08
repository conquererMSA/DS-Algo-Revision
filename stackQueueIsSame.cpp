#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.push(x);
    }
    int m;
    cin>>m;
    queue<int> q;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        q.push(x);
    }
    bool ans=true;
    if(q.size()==s.size()){
       while(!s.empty()){
        if(s.top()!=q.front()){
            ans=false;
            break;
        }
        s.pop();
        q.pop();
       }
    }
    else {
        ans=false;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}