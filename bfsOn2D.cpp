#include<bits/stdc++.h>
using namespace std;
char d2Grid[100][100];
bool visitedNode[100][100];
int n, m;
vector<pair<int, int>> childPath = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValid(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < m);
}
void bfsOn2DGrid(int sourceRow, int sourceCol){
    queue<pair<int, int>> q;
    q.push({sourceRow, sourceCol});
    visitedNode[sourceRow][sourceCol]=true;
    while(!q.empty()){
        pair<int, int> parent=q.front();
        q.pop();
        int parentRow=parent.first;
        int parentCol=parent.second;
        //ekhane unvisited and new node asbe.
        cout<<d2Grid[parentRow][parentCol]<<" ";
        for(int i=0; i<4; i++){
            int childRow=parentRow+childPath[i].first;
            int childCol=parentCol+childPath[i].second;
            if(isValid(childRow, childCol) && !visitedNode[childRow][childCol]){
                q.push({childRow, childCol});
                visitedNode[childRow][childCol]=true;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d2Grid[i][j];
        }
    }

    memset(visitedNode, false, sizeof(visitedNode));
    int sourceRow, sourceCol;
    cin >> sourceRow >> sourceCol;
    bfsOn2DGrid(sourceRow, sourceCol);
    return 0;
}