#include<bits/stdc++.h>
using namespace std;
//dp er size change valu er upor nirbor kore. ekhane changes variable hocce n and W. Tai dp er size n=3 and W=8 deya ace.
//dp er prottyekti index er initial value hobe -1
int dp[3][8];
int knapsackTopDown(int n,int W, int weight[],int val[]){
    if(n==0 || W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(weight[n]<=W){
        int pick=knapsackTopDown(n-1, W-weight[n],weight,val)+val[n];
        int noPick=knapsackTopDown(n-1,W,weight,val);
        return dp[n][W]=max(pick,noPick);
    }
    else return dp[n][W]=knapsackTopDown(n-1,W,weight,val);
}
int main(){
    int n,W; cin>>n>>W;
    int weight[n]; int val[n];
    for(int i=1; i<=n; i++){
        int w,v;
        cin>>w>>v;
        weight[i]=w, val[i]=v;
    }
    //before dp
    // int ans=knapsackTopDown(n,W,weight,val);
    // cout<<ans<<endl;

    //after dp
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            dp[i][j]=-1;
        }
    }
    int ans=knapsackTopDown(n,W,weight,val);
    cout<<"answer from knapsack "<<ans<<endl;
    cout<<"answer from dp "<<dp[n][W]<<endl;
    return 0;
}