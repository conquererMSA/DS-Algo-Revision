#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e; cin>>n>>e;
    vector<pair<int,int>> edgeList;
    while(e--){
        int u,v; cin>>u>>v;
        edgeList.push_back({u,v});
    }
    for(auto ed:edgeList){
        cout<<ed.first<<" "<<ed.second<<endl;
    }

    return 0;
}