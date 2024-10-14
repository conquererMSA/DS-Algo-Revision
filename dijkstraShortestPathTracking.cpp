#include <bits/stdc++.h>
using namespace std;
const int N = (1e5) + 5;
vector<pair<int, int>> graph[N];
int dis[N];
int parentNodesTracking[N];
bool visitedNode[N];

void dijkstraShortestPathTracking(int sourceNode) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[sourceNode] = 0;
    pq.push({dis[sourceNode], sourceNode}); // Push (distance, node)

    while (!pq.empty()) {
        pair<int, int> parent = pq.top(); // Get the top element of the priority queue
        pq.pop();

        int parentNode = parent.second;
        int parentCost = parent.first;

        // Relax edges of the current node
        for (pair<int, int> child : graph[parentNode]) {
            int childNode = child.second;
            int childCost = child.first;

            // Relaxation condition
            if (parentCost + childCost < dis[childNode]) {
                dis[childNode] = parentCost + childCost;
                parentNodesTracking[childNode] = parentNode;
                pq.push({dis[childNode], childNode});
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
        graph[u].push_back({w, v});
        graph[v].push_back({w, u}); // Undirected graph
    }

    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
        parentNodesTracking[i] = -1;
        visitedNode[i]=false;
    }

    int sourceNode;
    cin >> sourceNode;

    // Run Dijkstra's algorithm from the source node.
    dijkstraShortestPathTracking(sourceNode);

    if (dis[n] == INT_MAX || visitedNode[n]) { //ekhane n ke destination node dhora hoyeche.
        cout << "No path available" << endl;
        return 0;
    }

    // Track the path from `n` back to `sourceNode`.
    int currentNode = n;
    vector<int> pathTracking;
    while (currentNode != -1) {
        pathTracking.push_back(currentNode);
        if (currentNode == sourceNode) break;
        currentNode = parentNodesTracking[currentNode];
    }

    // Reverse to get the path from source to `n`.
    reverse(pathTracking.begin(), pathTracking.end());
    for (int pathNode : pathTracking) cout << pathNode << " ";
    return 0;
}
