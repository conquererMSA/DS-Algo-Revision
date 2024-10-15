#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int s;
    cin>>s;
    int dp[n+1][s+1];
    dp[0][0]=1;
    for(int i=1; i<=s; i++){
        dp[0][i]=0;
    }
    pair<int,int> cell;
    //i=1, j=0 hobe karon array value 0 hote pare.
    for(int i=1; i<=n; i++){
        for(int j=0; j<=s; j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
            //protom kunkun value use kore sum create kora possibel sei cell store kora hoyeche
            if(j==s && dp[i][j]==1){
                cell.first=i;
                cell.second=j;
            }
        }
    }
    //koyta value use kore kotovabe sum creat kora possible ta dp[i][j] theke jana jay.
    for(int i=0; i<=n; i++){
        for(int j=0; j<=s; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<cell.first<<" "<<cell.second<<endl;
    //array er sob gulu value use kore s koto vabe create kora possible ta dp[n][s] teke jana jay.
    if(dp[n][s]) cout<<dp[n][s]<<endl;
    return 0;
}