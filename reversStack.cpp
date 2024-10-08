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
    stack<int> rs;
    while(!s.empty()){
        rs.push(s.top());
        s.pop();
    }
    while(!rs.empty()){
        cout<<rs.top()<<" ";
        rs.pop();
    }
    return 0;
}