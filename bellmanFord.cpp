#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main() {
    int n, e; 
    cin >> n >> e;

    vector<Edge> edgeList;
    while (e--) {
        int u, v, w; 
        cin >> u >> v >> w;
        Edge edge(u, v, w);
        edgeList.push_back(edge);
    }

    int sourceNode; 
    cin >> sourceNode;

    vector<int> dis(n, INT_MAX);
    dis[sourceNode] = 0;

    // Bellman-Ford Algorithm: Relax edges (n-1) times.
    for (int i = 0; i <= n - 1; i++) {
        for (Edge ed : edgeList) {
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            // Relax edge (u, v) with weight w if possible.
            if (dis[u] < INT_MAX && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }

    // Check for negative weight cycles.
    bool cycle = false;
    for (Edge ed : edgeList) {
        if (dis[ed.u] < INT_MAX && dis[ed.u] + ed.w < dis[ed.v]) {
            cycle = true;
            break;
        }
    }

    // Output the result.
    if (cycle) {
        cout << "Negative cycle detected. No solution for shortest path distances." << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (dis[i] == INT_MAX) {
                cout << "Node " << i << " is unreachable from source " << sourceNode << "." << endl;
            } else {
                cout << "Shortest path to node " << i << " from source " << sourceNode << " is " << dis[i] << endl;
            }
        }
    }

    return 0;
}
