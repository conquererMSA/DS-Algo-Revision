#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
bool visitedNode[1005];
int nodeLevel[1005];
void trackinNodeLevelByBFS(int sourceNode){
    queue<pair<int,int>> q;
    q.push({sourceNode,0});
    nodeLevel[sourceNode]=0;
    visitedNode[sourceNode]=true;
    while(!q.empty()){
        pair<int,int> parent=q.front();
        int parentNode=parent.first;
        int parentNodeLevel=parent.second;
        q.pop();
        // cout<<parentNode<<" ";
        for(int child:graph[parentNode]){
            if(!visitedNode[child]){
                nodeLevel[child]=nodeLevel[parentNode]+1;
                q.push({child, nodeLevel[child]});
                visitedNode[child]=true;
            }
        }
    }
}
int main(){
    int n,e; cin>>n>>e;
    while(e--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int sourceNode; cin>>sourceNode; //zodi graph e source node na thake tahole source node ti print hoye/kaj kore queue loop bondho zabe. karon graph e kuno node na thake tar child o thakbe na.
    memset(visitedNode, false, sizeof(visitedNode));
    memset(nodeLevel, -1, sizeof(nodeLevel));
    trackinNodeLevelByBFS(sourceNode);
    for(int i=0; i<n; i++){
        cout<<"node "<<i<<" level "<<nodeLevel[i]<<endl;
    }
    return 0;
}