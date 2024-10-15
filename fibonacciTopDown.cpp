#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int fibonacciTopDown(int n){
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacciTopDown(n-1)+fibonacciTopDown(n-2);
}
int main(){
    int n; cin>>n;
    memset(dp,-1,sizeof(dp));
    int ans=fibonacciTopDown(n);
    cout<<ans<<endl;
    for(int i=1; i<=n; i++)cout<<dp[i]<<" ";
    //1 index ke dp kora hoy ni tai 1 index er value -1
    /*
    input:5
    output
    5
-1 1 2 3 5 
    */
    return 0;
}