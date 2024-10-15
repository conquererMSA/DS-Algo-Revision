#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int fibonacciTopDown(int n){
    if(n<2) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacciTopDown(n-1)+fibonacciTopDown(n-2);
}
int main(){
    int n; cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans=fibonacciTopDown(n);
    cout<<ans<<endl;
    return 0;
}