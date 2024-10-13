#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
bool visitedNode[1005];
int nodeLevel[1005];
int parentTracking[1005];
pair<bool, int> isConnected({false,NULL});
void trackingNodeLevelByDFS(int sourceNode, int destinationNode){
    nodeLevel[sourceNode]=0;
    visitedNode[sourceNode]=true;
    if(sourceNode==destinationNode){
            isConnected.first=true;
            isConnected.second=nodeLevel[sourceNode];
    }
    // cout<<sourceNode<<" ";
    for(int child:graph[sourceNode]){
            if(!visitedNode[child]){
                nodeLevel[child]=nodeLevel[sourceNode]+1;
                visitedNode[child]=true;
                parentTracking[child]=sourceNode;
                trackingNodeLevelByDFS(child, destinationNode);
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
    int sourceNode; cin>>sourceNode;
    int destinationNode; cin>>destinationNode;
    memset(visitedNode, false, sizeof(visitedNode));
    memset(nodeLevel, -1, sizeof(nodeLevel));
    memset(parentTracking, -1, sizeof(parentTracking));
    trackingNodeLevelByDFS(sourceNode, destinationNode);
    int x=destinationNode;
    vector<int> path;
    while(x!=-1){
        path.push_back(x);
        x=parentTracking[x];
    }
    reverse(path.begin(), path.end());
    for(int p:path) cout<<p<<" ";
}