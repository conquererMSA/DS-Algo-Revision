#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,val;
    cin>>n>>val;
    stack<int> st1;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st1.push(x);
    }
    stack<int> st2;
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    st2.push(val);
    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
    return 0;
}