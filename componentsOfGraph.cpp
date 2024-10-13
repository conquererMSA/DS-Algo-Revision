#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
bool visitedNode[100];
void componentCountByDFS(int sourceNode){
    cout<<sourceNode<<" ";
    visitedNode[sourceNode]=true;
    for(int child:graph[sourceNode]){
        if(!visitedNode[child]){
            componentCountByDFS(child);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int numberOfComponent=0;
    for(int i=0; i<6; i++){
        if(!visitedNode[i]){
            componentCountByDFS(i);
            numberOfComponent++;
        }
    }
    cout<<endl;
    cout<<numberOfComponent<<endl;
    return 0;
}