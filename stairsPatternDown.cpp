#include<bits/stdc++.h>
using namespace std;
/*
input: 5
output:
***
  ***
    ***
      ***
        ***

*/
int main(){
    int n;
    cin>>n;
    int sp=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sp; j++){
            cout<<" ";
        }
        for(int j=1; j<=3; j++){
            cout<<"*";
        }
        cout<<endl;
        sp+=2;
    }
    return 0;
}