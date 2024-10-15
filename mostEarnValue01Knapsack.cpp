#include<bits/stdc++.h>
using namespace std;
int knapsackTopDown(int n,int W, int weight[],int val[]){
    if(n==0 || W==0) return 0;
    if(weight[n]<=W){
        int pick=knapsackTopDown(n-1, W-weight[n],weight,val)+val[n];
        int noPick=knapsackTopDown(n-1,W,weight,val);
        return max(pick,noPick);
    }
    else return knapsackTopDown(n-1,W,weight,val);
}
int main(){
    int n,W; cin>>n>>W;
    int weight[n]; int val[n];
    for(int i=1; i<=n; i++){
        int w,v;
        cin>>w>>v;
        weight[i]=w, val[i]=v;
    }
    int ans=knapsackTopDown(n,W,weight,val);
    cout<<ans<<endl;
    return 0;
}