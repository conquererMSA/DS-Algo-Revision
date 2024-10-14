#include<bits/stdc++.h>
using namespace std;
//Floyed Warshal: all pair shortest path algorithme.
int main(){
    int n,e;
    cin>>n>>e;
    int graphWithCost[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            graphWithCost[i][j]=INT_MAX;
            if(i==j) graphWithCost[i][j]=0;
        }
    }
    while(e--){
        int u,v,w; cin>>u>>v>>w;
        graphWithCost[u][v]=w;
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graphWithCost[i][k]+graphWithCost[j][k]<graphWithCost[i][j]){
                    graphWithCost[i][j]=graphWithCost[i][k]+graphWithCost[j][k];
                }
            }
        }
    }
    //Floyed Warshal algo do not need a single source to get shortest path. Floyed Warshal algo store all possible shortest distance for each nodes.

    //cycle detection
    //2d grid er primary diagonal cell er kuno ekti cell er value zodi minus ba 0 theke chuto hoye zay tahole graph e negative weight cycle/cycle ace.
    bool cycle=false;
    for(int i=0; i<n; i++){
        if(graphWithCost[i][i]<0){
           cycle=true;
           break;
        }
    }
    if(cycle) cout<<"No shortest path availabe"<<endl;
    else cout<<graphWithCost[3][2]<<endl;
    return 0;
}