#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        q.push(x);
    }
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}