#include <bits/stdc++.h>
using namespace std;
const int N = (1e5) + 5;
vector<pair<int, int>> graph[N];
int distance[N]; // distance path relaxation e bar bar update hote pare.

class PathCompare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; // pair er second property te distance ache.
    }
};

void dijkstraPathRelaxation(int sourceNode) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, PathCompare> pq; // pq e thakbe node and node er relaxed path, tobe relaxed path abar relax hote pare.
    pq.push({sourceNode, 0}); // source node distance 0 hobe, -1 hole path relaxation hobe na.
    distance[sourceNode] = 0;

    while (!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.first;
        int parentCost = parent.second;

        // Relax the edges of the current node.
        for (pair<int, int> child : graph[parentNode]) {
            int childNode = child.first;
            int childCost = child.second;

            // Relaxation condition.
            if (parentCost + childCost < distance[childNode]) {
                distance[childNode] = childCost + parentCost;
                pq.push({childNode, distance[childNode]});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected graph
    }

    int sourceNode;
    cin >> sourceNode;

    // Initialize distance array with infinity.
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
    }

    // Run Dijkstra's algorithm from the given source node.
    dijkstraPathRelaxation(sourceNode);

    // Output the shortest distance from the source node to all other nodes.
    for (int i = 0; i < n; i++) {
        cout << "node " << i << " distance from " << sourceNode << " is " << distance[i] << endl;
    }

    return 0;
}
