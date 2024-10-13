#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
bool visitedNode[1005];
void bfs(int sourceNode){
    queue<int> q;
    q.push(sourceNode);
    visitedNode[sourceNode]=true;
    while(!q.empty()){
        int parentNode=q.front();
        q.pop();

        cout<<parentNode<<" ";

        for(int child:graph[parentNode]){
            if(!visitedNode[child]){
                q.push(child);
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
    bfs(sourceNode);
    return 0;
}