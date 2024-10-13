#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e; cin>>n>>e;
    int adjacencyMatrix[n][n]; //0 to 4
    memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));
    while(e--){
        int u,v;
        cin>>u>>v;
        adjacencyMatrix[u][v]=1;
        adjacencyMatrix[v][u]=1;
    }
    //check connection
    if(adjacencyMatrix[4][1]) cout<<"YES";
    else cout<<"NO"<<endl;
    return 0;
}