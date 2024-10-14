/*
MST ekti graph er multiple path and edge bad diye graph er total cost(weight) komiye ane and graph tike Tree te convert kore.  Zehetu MST multiple edge and path remove kore dey, sehtu kuno cycle create hoy na.

MST graph er sob gulu node ke less cost edge dara interconnect kore, graph er total cost komiye dey. Zodi kuno ekti node e visit korar ekdik path and cots thake tahole Kruskal algo less cost edge-path hisab kore. Beshi cost edge-path bad diye dey.

cost diye edgeList ke sort korte hobe.
check korte hobe edge er node gulu ekoi group er kina...
***MST n-1 bar cole
*/
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int parent[100], groupSize[100];

void dsuInit(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Initially, each node is its own parent
        groupSize[i] = 1;
    }
}

int dsuFind(int node) {
    if (parent[node] != node) {
        parent[node] = dsuFind(parent[node]);  // Path compression
    }
    return parent[node];
}

void dsuUnion(int u, int v) {
    int leaderU = dsuFind(u);
    int leaderV = dsuFind(v);
    if (leaderU != leaderV) {
        // Union by size: attach the smaller tree to the larger tree
        if (groupSize[leaderU] > groupSize[leaderV]) {
            parent[leaderV] = leaderU;
            groupSize[leaderU] += groupSize[leaderV];
        } else {
            parent[leaderU] = leaderV;
            groupSize[leaderV] += groupSize[leaderU];
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    // Sort edges by their weights in ascending order
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    dsuInit(n);
    int minimumConnectionCost = 0;
    int edgesUsed = 0;

    // Iterate through the sorted edges
    for (const Edge &edge : edges) {
        if (dsuFind(edge.u) != dsuFind(edge.v)) {
            dsuUnion(edge.u, edge.v);
            minimumConnectionCost += edge.w;
            edgesUsed++;
            // Early exit if we've used n - 1 edges (which means MST is complete)
            if (edgesUsed == n - 1) break;
        }
    }

    // Output the minimum cost to connect all nodes
    cout << minimumConnectionCost << endl;
    return 0;
}

/*
input
5 7
0 1 2
0 2 3
0 3 3
3 4 6
2 4 4
2 1 7
1 4 5

output
12
*/