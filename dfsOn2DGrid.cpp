#include <bits/stdc++.h>
using namespace std;

char d2Grid[100][100];
bool visitedNode[100][100];
int n, m;
vector<pair<int, int>> childPath = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValid(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < m);
}
void dfsOn2DGrid(int sourceRow, int sourceCol) {
    visitedNode[sourceRow][sourceCol] = true;
    cout << d2Grid[sourceRow][sourceCol] << " "; //workspace
    for (int i = 0; i < 4; i++) {
        int childRow = sourceRow + childPath[i].first;
        int childCol = sourceCol + childPath[i].second;
        if (isValid(childRow, childCol) && !visitedNode[childRow][childCol]) {
            dfsOn2DGrid(childRow, childCol);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d2Grid[i][j];
        }
    }

    memset(visitedNode, false, sizeof(visitedNode));
    int sourceRow, sourceCol;
    cin >> sourceRow >> sourceCol;
    dfsOn2DGrid(sourceRow, sourceCol);

    return 0;
}
