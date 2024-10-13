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

    int numberOfComponent = 0;
    for (int i = 0; i < n; i++) {
        if (!visitedNode[i]) {
            componentCountByDFS(i);
            numberOfComponent++;
        }
    }

    cout << numberOfComponent << endl;
    return 0;
}
