#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    int d2[r][c];
    int midR=r/2, midC=c/2;
    cout<<midR<<midC<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i==midR && j==midC) cout<<'X';
            else if(i==j) cout<<'\\';
            else if(i+j==r-1) cout<<'/';
            else cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}