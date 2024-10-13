#include <bits/stdc++.h>
using namespace std;

// Define the 2D grid size
int d2Grid[100][100];
bool visitedNode[100][100];
pair<int, int> parentTracking[100][100]; // To store the parent of each node
int n, m;

// Directions for moving in the grid (right, left, up, down)
vector<pair<int, int>> childPath = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// Function to check if a cell is within the grid boundaries and not visited
bool isValid(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < m);
}

// DFS function to explore the grid
void dfsOn2DGrid(int sourceRow, int sourceCol) {
    visitedNode[sourceRow][sourceCol] = true;

    // Traverse through each possible direction
    for (auto [dx, dy] : childPath) {
        int childRow = sourceRow + dx;
        int childCol = sourceCol + dy;

        // Check if the child cell is valid and not yet visited
        if (isValid(childRow, childCol) && !visitedNode[childRow][childCol]) {
            // Set the parent of the child node as the current node
            parentTracking[childRow][childCol] = {sourceRow, sourceCol};

            // Perform DFS on the child node
            dfsOn2DGrid(childRow, childCol);
        }
    }
}

int main() {
    int row, col;
    cin >> row >> col;
    n = row;
    m = col;

    // Input the grid values
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> d2Grid[i][j];
        }
    }

    // Initialize visited and parentTracking arrays
    memset(visitedNode, false, sizeof(visitedNode));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            parentTracking[i][j] = {-1, -1}; // Initialize with an invalid parent
        }
    }

    // Source node for DFS traversal
    int sourceRow, sourceCol;
    cin >> sourceRow >> sourceCol;

    // Perform DFS starting from the source node
    dfsOn2DGrid(sourceRow, sourceCol);

    // Output the parent of each node that was visited
    cout << "Parent nodes of each visited cell:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visitedNode[i][j]) {
                cout << "Cell (" << i << ", " << j << ") has parent ("
                     << parentTracking[i][j].first << ", "
                     << parentTracking[i][j].second << ")" << endl;
            }
        }
    }

    return 0;
}
