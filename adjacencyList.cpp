#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, e; cin>>n>>e;
    vector<int> adjacencyList[n];
    while(e--){
        int u,v; cin>>u>>v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    for(int child:adjacencyList[3]){
        cout<<child<<" ";
    }
    return 0;
}