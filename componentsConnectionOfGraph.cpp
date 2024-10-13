#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visitedNode[100];

void componentCountByDFS(int sourceNode) {
    visitedNode[sourceNode] = true;
    for (int child : graph[sourceNode]) {
        if (!visitedNode[child]) {
            componentCountByDFS(child);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> eachComponentNode;
    memset(visitedNode, false, sizeof(visitedNode));

    // Find all components and store a representative node from each.
    for (int i = 0; i < n; i++) {
        if (!visitedNode[i]) {
            eachComponentNode.push_back(i);
            componentCountByDFS(i);
        }
    }

    // If there are multiple components, connect them by adding edges.
    for (int i = 0; i < eachComponentNode.size() - 1; i++) {
        int u = eachComponentNode[i];
        int v = eachComponentNode[i + 1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Reset visited array to count the number of connected components again.
    memset(visitedNode, false, sizeof(visitedNode));
    int numberOfComponents = 0;

    // Count the number of components after connecting.
    for (int i = 0; i < n; i++) {
        if (!visitedNode[i]) {
            componentCountByDFS(i);
            numberOfComponents++;
        }
    }

    cout << numberOfComponents << endl;
    return 0;
}