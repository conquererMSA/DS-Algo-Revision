#include<bits/stdc++.h>
using namespace std;
/*
minimum subset sum difference
4
1 5 4 11
ei charta value dui joner moddhye emon vabe vag kore dao, zeno difference ta sorbonimno hoy. ekjon ke 1+5+4 dile 10 hoy and arekjon ke 11 dile tader moddhye difference hoy 1. za sorbonimno.
*/
int main(){
    int n;
    cin>>n;
    int a[n];
    int s=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        s+=a[i];
    }
    int dp[n+1][s+1];
    dp[0][0]=1;
    for(int i=1; i<=s; i++) dp[0][i]=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=s; j++){
             if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
             }
             else dp[i][j]=dp[i-1][j];
        }
    }
    vector<int> v;
    for(int j=0; j<=s; j++){
        if(dp[n][j]==1) v.push_back(j);
    }
    int ans=INT_MAX;
    for(int val:v){
        int s1=val;
        int s2=s-s1;
        ans=min(ans, abs(s2-s1));
    }
    cout<<ans<<endl;
    return 0;
}