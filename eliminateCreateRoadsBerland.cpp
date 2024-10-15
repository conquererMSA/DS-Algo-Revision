#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int group_size[N];

// Initialize DSU structures
void dsu_initialize(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;    // Each city is initially its own leader
        group_size[i] = 1; // The size of each group is 1
    }
}

// Find the leader of a city with path compression
int dsu_find(int node) {
    if (parent[node] == -1)
        return node;
    return parent[node] = dsu_find(parent[node]); // Path compression
}

// Union two cities by the size of their groups
void dsu_union_by_size(int node1, int node2) {
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    
    // If they are already in the same component, do nothing
    if (leaderA == leaderB) return;

    // Union by size: attach the smaller tree under the larger one
    if (group_size[leaderA] > group_size[leaderB]) {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    } else {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main() {
    int n;
    cin >> n;
    
    dsu_initialize(n);

    vector<pair<int, int>> bad; // Stores redundant roads
    vector<pair<int, int>> create; // Stores new roads to create

    // Read and process all roads
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB) {
            // If they are already connected, this road is redundant
            bad.push_back({a, b});
        } else {
            // Otherwise, unite the two components
            dsu_union_by_size(a, b);
        }
    }

    // Now, reconnect remaining components with new roads
    for (int i = 2; i <= n; i++) {
        int leaderA = dsu_find(1);
        int leaderB = dsu_find(i);

        if (leaderA != leaderB) {
            // If city `i` is not connected to city `1`, connect them
            create.push_back({1, i});
            dsu_union_by_size(1, i);
        }
    }

    // Output the number of redundant roads (which is equal to the number of changes)
    cout << bad.size() << endl;

    // Output each bad road and its corresponding new road
    for (int i = 0; i < bad.size(); i++) {
        cout << bad[i].first << " " << bad[i].second << " " 
             << create[i].first << " " << create[i].second << endl;
    }

    return 0;
}
