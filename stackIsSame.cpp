#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st.push(x);
    }
    int m;
    cin>>m;
    stack<int> st2;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        st2.push(x);
    }
    bool ans=true;
    if(m==n){
       while(!st.empty()){
        if(st.top()!=st2.top()){ 
            ans=false;
            break;
            }
            st.pop();
            st2.pop();
       }
    }else {
        ans=false;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}