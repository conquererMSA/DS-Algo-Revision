#include<bits/stdc++.h>
using namespace std;
int main(){
    int testCases; cin>>testCases;
    while(testCases--){
        int n; cin>>n;
    int numOfEven=0, numOfOdd=0;
    for(int i=1; i<=n; i++){
        int x; cin>>x;
        if(x%2==0) numOfEven+=1;
        if(x%2!=0) numOfOdd+=1;
    }
    int numberOfOperation=-1;
    if(numOfEven==numOfOdd) numberOfOperation=0;
    else if(numOfEven==n || numOfOdd==n){
        numberOfOperation=n/2;
    }
    cout<<numberOfOperation<<endl;
    }

    return 0;
}